
// Generated from Kafe.g by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "KafeParser.h"


namespace kafe {

/**
 * This interface defines an abstract listener for a parse tree produced by KafeParser.
 */
class  KafeListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterChunk(KafeParser::ChunkContext *ctx) = 0;
  virtual void exitChunk(KafeParser::ChunkContext *ctx) = 0;

  virtual void enterBlock(KafeParser::BlockContext *ctx) = 0;
  virtual void exitBlock(KafeParser::BlockContext *ctx) = 0;

  virtual void enterStat(KafeParser::StatContext *ctx) = 0;
  virtual void exitStat(KafeParser::StatContext *ctx) = 0;

  virtual void enterRetstat(KafeParser::RetstatContext *ctx) = 0;
  virtual void exitRetstat(KafeParser::RetstatContext *ctx) = 0;

  virtual void enterType(KafeParser::TypeContext *ctx) = 0;
  virtual void exitType(KafeParser::TypeContext *ctx) = 0;

  virtual void enterExplist(KafeParser::ExplistContext *ctx) = 0;
  virtual void exitExplist(KafeParser::ExplistContext *ctx) = 0;

  virtual void enterFunctioncall(KafeParser::FunctioncallContext *ctx) = 0;
  virtual void exitFunctioncall(KafeParser::FunctioncallContext *ctx) = 0;

  virtual void enterExp(KafeParser::ExpContext *ctx) = 0;
  virtual void exitExp(KafeParser::ExpContext *ctx) = 0;

  virtual void enterArgslist(KafeParser::ArgslistContext *ctx) = 0;
  virtual void exitArgslist(KafeParser::ArgslistContext *ctx) = 0;

  virtual void enterFuncbody(KafeParser::FuncbodyContext *ctx) = 0;
  virtual void exitFuncbody(KafeParser::FuncbodyContext *ctx) = 0;

  virtual void enterStructbody(KafeParser::StructbodyContext *ctx) = 0;
  virtual void exitStructbody(KafeParser::StructbodyContext *ctx) = 0;

  virtual void enterOperatorOr(KafeParser::OperatorOrContext *ctx) = 0;
  virtual void exitOperatorOr(KafeParser::OperatorOrContext *ctx) = 0;

  virtual void enterOperatorAnd(KafeParser::OperatorAndContext *ctx) = 0;
  virtual void exitOperatorAnd(KafeParser::OperatorAndContext *ctx) = 0;

  virtual void enterOperatorComparison(KafeParser::OperatorComparisonContext *ctx) = 0;
  virtual void exitOperatorComparison(KafeParser::OperatorComparisonContext *ctx) = 0;

  virtual void enterOperatorStrcat(KafeParser::OperatorStrcatContext *ctx) = 0;
  virtual void exitOperatorStrcat(KafeParser::OperatorStrcatContext *ctx) = 0;

  virtual void enterOperatorAddSub(KafeParser::OperatorAddSubContext *ctx) = 0;
  virtual void exitOperatorAddSub(KafeParser::OperatorAddSubContext *ctx) = 0;

  virtual void enterOperatorMulDivMod(KafeParser::OperatorMulDivModContext *ctx) = 0;
  virtual void exitOperatorMulDivMod(KafeParser::OperatorMulDivModContext *ctx) = 0;

  virtual void enterOperatorBitwise(KafeParser::OperatorBitwiseContext *ctx) = 0;
  virtual void exitOperatorBitwise(KafeParser::OperatorBitwiseContext *ctx) = 0;

  virtual void enterOperatorUnary(KafeParser::OperatorUnaryContext *ctx) = 0;
  virtual void exitOperatorUnary(KafeParser::OperatorUnaryContext *ctx) = 0;

  virtual void enterOperatorPower(KafeParser::OperatorPowerContext *ctx) = 0;
  virtual void exitOperatorPower(KafeParser::OperatorPowerContext *ctx) = 0;

  virtual void enterNumber(KafeParser::NumberContext *ctx) = 0;
  virtual void exitNumber(KafeParser::NumberContext *ctx) = 0;

  virtual void enterString(KafeParser::StringContext *ctx) = 0;
  virtual void exitString(KafeParser::StringContext *ctx) = 0;

  virtual void enterList(KafeParser::ListContext *ctx) = 0;
  virtual void exitList(KafeParser::ListContext *ctx) = 0;


};

}  // namespace kafe
