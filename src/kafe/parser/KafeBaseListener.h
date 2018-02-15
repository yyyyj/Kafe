
// Generated from Kafe.g by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "KafeListener.h"


namespace kafe {

/**
 * This class provides an empty implementation of KafeListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  KafeBaseListener : public KafeListener {
public:

  virtual void enterChunk(KafeParser::ChunkContext * /*ctx*/) override { }
  virtual void exitChunk(KafeParser::ChunkContext * /*ctx*/) override { }

  virtual void enterBlock(KafeParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(KafeParser::BlockContext * /*ctx*/) override { }

  virtual void enterStat(KafeParser::StatContext * /*ctx*/) override { }
  virtual void exitStat(KafeParser::StatContext * /*ctx*/) override { }

  virtual void enterRetstat(KafeParser::RetstatContext * /*ctx*/) override { }
  virtual void exitRetstat(KafeParser::RetstatContext * /*ctx*/) override { }

  virtual void enterType(KafeParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(KafeParser::TypeContext * /*ctx*/) override { }

  virtual void enterExplist(KafeParser::ExplistContext * /*ctx*/) override { }
  virtual void exitExplist(KafeParser::ExplistContext * /*ctx*/) override { }

  virtual void enterFunctioncall(KafeParser::FunctioncallContext * /*ctx*/) override { }
  virtual void exitFunctioncall(KafeParser::FunctioncallContext * /*ctx*/) override { }

  virtual void enterExp(KafeParser::ExpContext * /*ctx*/) override { }
  virtual void exitExp(KafeParser::ExpContext * /*ctx*/) override { }

  virtual void enterArgslist(KafeParser::ArgslistContext * /*ctx*/) override { }
  virtual void exitArgslist(KafeParser::ArgslistContext * /*ctx*/) override { }

  virtual void enterFuncbody(KafeParser::FuncbodyContext * /*ctx*/) override { }
  virtual void exitFuncbody(KafeParser::FuncbodyContext * /*ctx*/) override { }

  virtual void enterStructbody(KafeParser::StructbodyContext * /*ctx*/) override { }
  virtual void exitStructbody(KafeParser::StructbodyContext * /*ctx*/) override { }

  virtual void enterOperatorOr(KafeParser::OperatorOrContext * /*ctx*/) override { }
  virtual void exitOperatorOr(KafeParser::OperatorOrContext * /*ctx*/) override { }

  virtual void enterOperatorAnd(KafeParser::OperatorAndContext * /*ctx*/) override { }
  virtual void exitOperatorAnd(KafeParser::OperatorAndContext * /*ctx*/) override { }

  virtual void enterOperatorComparison(KafeParser::OperatorComparisonContext * /*ctx*/) override { }
  virtual void exitOperatorComparison(KafeParser::OperatorComparisonContext * /*ctx*/) override { }

  virtual void enterOperatorStrcat(KafeParser::OperatorStrcatContext * /*ctx*/) override { }
  virtual void exitOperatorStrcat(KafeParser::OperatorStrcatContext * /*ctx*/) override { }

  virtual void enterOperatorAddSub(KafeParser::OperatorAddSubContext * /*ctx*/) override { }
  virtual void exitOperatorAddSub(KafeParser::OperatorAddSubContext * /*ctx*/) override { }

  virtual void enterOperatorMulDivMod(KafeParser::OperatorMulDivModContext * /*ctx*/) override { }
  virtual void exitOperatorMulDivMod(KafeParser::OperatorMulDivModContext * /*ctx*/) override { }

  virtual void enterOperatorBitwise(KafeParser::OperatorBitwiseContext * /*ctx*/) override { }
  virtual void exitOperatorBitwise(KafeParser::OperatorBitwiseContext * /*ctx*/) override { }

  virtual void enterOperatorUnary(KafeParser::OperatorUnaryContext * /*ctx*/) override { }
  virtual void exitOperatorUnary(KafeParser::OperatorUnaryContext * /*ctx*/) override { }

  virtual void enterOperatorPower(KafeParser::OperatorPowerContext * /*ctx*/) override { }
  virtual void exitOperatorPower(KafeParser::OperatorPowerContext * /*ctx*/) override { }

  virtual void enterNumber(KafeParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(KafeParser::NumberContext * /*ctx*/) override { }

  virtual void enterString(KafeParser::StringContext * /*ctx*/) override { }
  virtual void exitString(KafeParser::StringContext * /*ctx*/) override { }

  virtual void enterList(KafeParser::ListContext * /*ctx*/) override { }
  virtual void exitList(KafeParser::ListContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace kafe
