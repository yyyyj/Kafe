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

#ifndef kafe_parser_visitor
#define kafe_parser_visitor

#include "antlr4-runtime.h"

#include <kafe/generated/KafeVisitor.h>
#include <kafe/parser/generator.hpp>

namespace kafe
{
    namespace abc
    {
        
        template<typename T> bool instanceOf(antlr4::tree::ParseTree* ctx)
        {
            return dynamic_cast<T*>(ctx); // dynamic_cast will return nullptr if it fails to cast something to a ptr type
        }

        class Visitor : public KafeVisitor
        {
        private:
            Generator* m_gen;

        public:
            Visitor();
            Visitor(Generator* generator);
            ~Visitor();

            virtual antlrcpp::Any visitChunk(KafeParser::ChunkContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitBlock(KafeParser::BlockContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitStat(KafeParser::StatContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitRetstat(KafeParser::RetstatContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitVarqualifier(KafeParser::VarqualifierContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitType(KafeParser::TypeContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitNamelist(KafeParser::NamelistContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitExplist(KafeParser::ExplistContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitGetstructmember(KafeParser::GetstructmemberContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitFunctioncall(KafeParser::FunctioncallContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitExp(KafeParser::ExpContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitArgslist(KafeParser::ArgslistContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitFuncbody(KafeParser::FuncbodyContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitStructbody(KafeParser::StructbodyContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitOperatorOr(KafeParser::OperatorOrContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitOperatorAnd(KafeParser::OperatorAndContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitOperatorComparison(KafeParser::OperatorComparisonContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitOperatorStrcat(KafeParser::OperatorStrcatContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitOperatorAddSub(KafeParser::OperatorAddSubContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitOperatorMulDivMod(KafeParser::OperatorMulDivModContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitOperatorBitwise(KafeParser::OperatorBitwiseContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitOperatorUnary(KafeParser::OperatorUnaryContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitOperatorPower(KafeParser::OperatorPowerContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitOperatorMathAffectation(KafeParser::OperatorMathAffectationContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitNumber(KafeParser::NumberContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitString(KafeParser::StringContext *context) { return antlrcpp::Any(); }
            virtual antlrcpp::Any visitList(KafeParser::ListContext *context) { return antlrcpp::Any(); }
        };
        
    }  // namespace abc
}  // namespace kafe

#endif  // kafe_parser_visitor