
#ifdef _MSC_VER
    // if compiling with visual studio, disable those warnings
    #pragma warning (disable: 4251)  // need a dll to run
    #pragma warning (disable: 4996)  // warnings from codecvt
#endif


// Generated from grammar/Kafe.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "KafeParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by KafeParser.
 */
class  KafeVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by KafeParser.
   */
    virtual antlrcpp::Any visitChunk(KafeParser::ChunkContext *context) = 0;

    virtual antlrcpp::Any visitBlock(KafeParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitStat(KafeParser::StatContext *context) = 0;

    virtual antlrcpp::Any visitRetstat(KafeParser::RetstatContext *context) = 0;

    virtual antlrcpp::Any visitVarqualifier(KafeParser::VarqualifierContext *context) = 0;

    virtual antlrcpp::Any visitType(KafeParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitNamelist(KafeParser::NamelistContext *context) = 0;

    virtual antlrcpp::Any visitExplist(KafeParser::ExplistContext *context) = 0;

    virtual antlrcpp::Any visitGetstructmember(KafeParser::GetstructmemberContext *context) = 0;

    virtual antlrcpp::Any visitFunctioncall(KafeParser::FunctioncallContext *context) = 0;

    virtual antlrcpp::Any visitExp(KafeParser::ExpContext *context) = 0;

    virtual antlrcpp::Any visitArgslist(KafeParser::ArgslistContext *context) = 0;

    virtual antlrcpp::Any visitFuncbody(KafeParser::FuncbodyContext *context) = 0;

    virtual antlrcpp::Any visitStructparents(KafeParser::StructparentsContext *context) = 0;

    virtual antlrcpp::Any visitStructbody(KafeParser::StructbodyContext *context) = 0;

    virtual antlrcpp::Any visitOperatorOr(KafeParser::OperatorOrContext *context) = 0;

    virtual antlrcpp::Any visitOperatorAnd(KafeParser::OperatorAndContext *context) = 0;

    virtual antlrcpp::Any visitOperatorComparison(KafeParser::OperatorComparisonContext *context) = 0;

    virtual antlrcpp::Any visitOperatorStrcat(KafeParser::OperatorStrcatContext *context) = 0;

    virtual antlrcpp::Any visitOperatorAddSub(KafeParser::OperatorAddSubContext *context) = 0;

    virtual antlrcpp::Any visitOperatorMulDivMod(KafeParser::OperatorMulDivModContext *context) = 0;

    virtual antlrcpp::Any visitOperatorBitwise(KafeParser::OperatorBitwiseContext *context) = 0;

    virtual antlrcpp::Any visitOperatorUnary(KafeParser::OperatorUnaryContext *context) = 0;

    virtual antlrcpp::Any visitOperatorPower(KafeParser::OperatorPowerContext *context) = 0;

    virtual antlrcpp::Any visitOperatorMathAffectation(KafeParser::OperatorMathAffectationContext *context) = 0;

    virtual antlrcpp::Any visitNumber(KafeParser::NumberContext *context) = 0;

    virtual antlrcpp::Any visitString(KafeParser::StringContext *context) = 0;

    virtual antlrcpp::Any visitList(KafeParser::ListContext *context) = 0;


};

