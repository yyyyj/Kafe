
// Generated from grammar/Kafe.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "KafeVisitor.h"


/**
 * This class provides an empty implementation of KafeVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  KafeBaseVisitor : public KafeVisitor {
public:

  virtual antlrcpp::Any visitChunk(KafeParser::ChunkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(KafeParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStat(KafeParser::StatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRetstat(KafeParser::RetstatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarqualifier(KafeParser::VarqualifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(KafeParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNamelist(KafeParser::NamelistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExplist(KafeParser::ExplistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGetstructmember(KafeParser::GetstructmemberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctioncall(KafeParser::FunctioncallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExp(KafeParser::ExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgslist(KafeParser::ArgslistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncbody(KafeParser::FuncbodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructbody(KafeParser::StructbodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperatorOr(KafeParser::OperatorOrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperatorAnd(KafeParser::OperatorAndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperatorComparison(KafeParser::OperatorComparisonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperatorStrcat(KafeParser::OperatorStrcatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperatorAddSub(KafeParser::OperatorAddSubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperatorMulDivMod(KafeParser::OperatorMulDivModContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperatorBitwise(KafeParser::OperatorBitwiseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperatorUnary(KafeParser::OperatorUnaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperatorPower(KafeParser::OperatorPowerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperatorMathAffectation(KafeParser::OperatorMathAffectationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber(KafeParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitString(KafeParser::StringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList(KafeParser::ListContext *ctx) override {
    return visitChildren(ctx);
  }


};

