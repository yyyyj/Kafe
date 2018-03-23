/*
 * Kafe - A programming language running on a VM
 * 
 * Copyright (c) 2018 SuperFola and the Kafe open source project
 * Licensed under MPL-2.0
 * 
 * This notice may not be removed or altered from any source ditribution
 * 
 * See https://superfola.github.io/Kafe/CONTRIBUTORS.txt for the list of Kafe project authors
 * See https://superfola.github.io/Kafe/LICENSE for license information
 */

#ifndef kafe_vm
#define kafe_vm

#include <kafe/vm/instructions.hpp>
#include <kafe/types.hpp>
#include <kafe/utils.hpp>
#include <kafe/vm/value.hpp>
#include <kafe/KafeException.hpp>
#include <kafe/vm/bytecodeBlocksMaker.hpp>
#include <kafe/vm/errorHandler.hpp>
#include <kafe/vm/bytecode.hpp>
#include <kafe/plugins/packager.hpp>

#include <string>
#include <vector>
#include <fstream>
#include <exception>
#include <stdexcept>
#include <sygmei/functiondb.hpp>

namespace kafe
{

    class VM
    {
    private:
        addr_t m_stack_size;
        addr_t m_ip;
        ValueStack_t m_stack;
        // variable name => Value
        VarStack_t m_variables;
        // keeping track of the segments' calls
        CallStack_t m_call_stack;
        // keeping the signatures of the declared structures
        // name of the struct : object Structure (.elements => name of the var : default value)
        StructureMap_t m_struct_definitions;
        // keeping the loaded bytecode into the VM to use easily without passing it around
        abc::Bytecode m_bytecode;
        abc::BytecodeBlocksMaker m_bbm;
        int m_debug_mode;
        addr_t m_interactive_advance;
        bool m_has_been_dirty_clean;
        abc::ErrorHandler m_errh;
        // we'll store the procedures and all that stuff inside this db, and use another one for user define functions
        FunctionDatabase m_fdb;
        FunctionDatabase m_fdb_user;
        // we must keep the dll modules, otherway they would be destructed and unloaded
        std::vector<abc::DLLModule> m_dlls;

        void     push      (Value value);
        Value    pop       ();
        void     dirtyClear();
        void     clear     ();
        void     loadLib   ();
        VarFound findVar   (const str_t& varName);
        Value    getVar    (const str_t& varName, VarFound vf);
        Value&   getRefVar (const str_t& varName, VarFound vf);
        void     setVar    (const str_t& varName, Value v, VarFound vf, bool is_const=false);
        void     delVar    (const str_t& varName);
        // about segments and jumps
        void        performJump   (bool registerCall=true);
        void        retFromSegment();
        // execution stuff
        void exec_handleDataTypesDecl (inst_t instruction);
        void exec_handleStructures    (inst_t instruction);
        void exec_handleVariableThings(inst_t instruction);
        void exec_handleListThings    (inst_t instruction);
        void exec_handleSegments      (inst_t instruction);
        void exec_handleBuiltins      ();

        void interactiveMode(inst_t instruction, bool displayOnly=false);

    public:
        VM();
        ~VM();

        // the debug flags for the VM
        static const int FLAG_DEFAULT_MODE = 0;
        static const int FLAG_BASIC_DEBUG  = 1 << 0;
        static const int FLAG_INTERACTIVE  = 1 << 1;
        static const int FLAG_EXPERIMENTAL = 1 << 2;

        bytecode_t readFile(const std::string& filePath);

        int  execFromFile(const std::string& filePath);
        void setMode     (int mode);
        void load        (bytecode_t bytecode);
        int  exec        ();

        void registerFunction(const std::string& name, functionPtr fct);
        void loadDLL         (const std::string& name);

        template <typename T> void push(T value)
        {
            ValueType t = Value::guessType<T>();
            if (t == ValueType::Unknown)
                raiseException(Exception::CRITIC, "Can not guess value type when trying to push a value on the stack");
            Value c(t, value);
            push(c);
        }

        ValueStack_t& getStack();
        VarStack_t&   getVariables();
        void saveBytecode(const std::string& filename);
    };

}  // namespace kafe

#endif // kafe_vm
