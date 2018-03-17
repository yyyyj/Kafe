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

#include <kafe/generated/KafeVisitor.h>

namespace kafe
{

    // forward declaration
    class Parser;

    namespace abc
    {
        
        template<typename T> bool instanceOf(tree::ParseTree* ctx)
        {
            return dynamic_cast<T*>(ctx); // dynamic_cast will return nullptr if it fails to cast something to a ptr type
        }

        class Visitor : public KafeVisitor
        {
        private:
            Parser* m_parser;

        public:
            Visitor(Parser* parser);
            ~Visitor();

            virtual antlrcpp::Any visitChunk(KafeParser::ChunkContext *context);
            virtual antlrcpp::Any visitBlock(KafeParser::BlockContext *context);
            virtual antlrcpp::Any visitStat(KafeParser::StatContext *context);
            virtual antlrcpp::Any visitRetstat(KafeParser::RetstatContext *context);
            virtual antlrcpp::Any visitVarqualifier(KafeParser::VarqualifierContext *context);
            virtual antlrcpp::Any visitType(KafeParser::TypeContext *context);
            virtual antlrcpp::Any visitNamelist(KafeParser::NamelistContext *context);
            virtual antlrcpp::Any visitExplist(KafeParser::ExplistContext *context);
            virtual antlrcpp::Any visitGetstructmember(KafeParser::GetstructmemberContext *context);
            virtual antlrcpp::Any visitFunctioncall(KafeParser::FunctioncallContext *context);
            virtual antlrcpp::Any visitExp(KafeParser::ExpContext *context);
            virtual antlrcpp::Any visitArgslist(KafeParser::ArgslistContext *context);
            virtual antlrcpp::Any visitFuncbody(KafeParser::FuncbodyContext *context);
            virtual antlrcpp::Any visitStructbody(KafeParser::StructbodyContext *context);
            virtual antlrcpp::Any visitOperatorOr(KafeParser::OperatorOrContext *context);
            virtual antlrcpp::Any visitOperatorAnd(KafeParser::OperatorAndContext *context);
            virtual antlrcpp::Any visitOperatorComparison(KafeParser::OperatorComparisonContext *context);
            virtual antlrcpp::Any visitOperatorStrcat(KafeParser::OperatorStrcatContext *context);
            virtual antlrcpp::Any visitOperatorAddSub(KafeParser::OperatorAddSubContext *context);
            virtual antlrcpp::Any visitOperatorMulDivMod(KafeParser::OperatorMulDivModContext *context);
            virtual antlrcpp::Any visitOperatorBitwise(KafeParser::OperatorBitwiseContext *context);
            virtual antlrcpp::Any visitOperatorUnary(KafeParser::OperatorUnaryContext *context);
            virtual antlrcpp::Any visitOperatorPower(KafeParser::OperatorPowerContext *context);
            virtual antlrcpp::Any visitOperatorMathAffectation(KafeParser::OperatorMathAffectationContext *context);
            virtual antlrcpp::Any visitNumber(KafeParser::NumberContext *context);
            virtual antlrcpp::Any visitString(KafeParser::StringContext *context);
            virtual antlrcpp::Any visitList(KafeParser::ListContext *context);
        };
        
    }  // namespace abc
}  // namespace kafe

#endif  // kafe_parser_visitor