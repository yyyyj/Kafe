
// Generated from Kafe.g by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace kafe {


class  KafeParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, T__33 = 34, T__34 = 35, T__35 = 36, T__36 = 37, T__37 = 38, 
    T__38 = 39, T__39 = 40, T__40 = 41, T__41 = 42, T__42 = 43, T__43 = 44, 
    T__44 = 45, T__45 = 46, T__46 = 47, T__47 = 48, T__48 = 49, T__49 = 50, 
    T__50 = 51, T__51 = 52, T__52 = 53, T__53 = 54, T__54 = 55, T__55 = 56, 
    T__56 = 57, T__57 = 58, T__58 = 59, T__59 = 60, T__60 = 61, T__61 = 62, 
    T__62 = 63, T__63 = 64, T__64 = 65, NAME = 66, NORMALSTRING = 67, CHARSTRING = 68, 
    INT = 69, HEX = 70, FLOAT = 71, HEX_FLOAT = 72, COMMENT = 73, WS = 74
  };

  enum {
    RuleChunk = 0, RuleBlock = 1, RuleStat = 2, RuleRetstat = 3, RuleType = 4, 
    RuleExplist = 5, RuleGetstructmember = 6, RuleFunctioncall = 7, RuleExp = 8, 
    RuleArgslist = 9, RuleFuncbody = 10, RuleStructbody = 11, RuleOperatorOr = 12, 
    RuleOperatorAnd = 13, RuleOperatorComparison = 14, RuleOperatorStrcat = 15, 
    RuleOperatorAddSub = 16, RuleOperatorMulDivMod = 17, RuleOperatorBitwise = 18, 
    RuleOperatorUnary = 19, RuleOperatorPower = 20, RuleOperatorMathAffectation = 21, 
    RuleNumber = 22, RuleString = 23, RuleList = 24
  };

  KafeParser(antlr4::TokenStream *input);
  ~KafeParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ChunkContext;
  class BlockContext;
  class StatContext;
  class RetstatContext;
  class TypeContext;
  class ExplistContext;
  class GetstructmemberContext;
  class FunctioncallContext;
  class ExpContext;
  class ArgslistContext;
  class FuncbodyContext;
  class StructbodyContext;
  class OperatorOrContext;
  class OperatorAndContext;
  class OperatorComparisonContext;
  class OperatorStrcatContext;
  class OperatorAddSubContext;
  class OperatorMulDivModContext;
  class OperatorBitwiseContext;
  class OperatorUnaryContext;
  class OperatorPowerContext;
  class OperatorMathAffectationContext;
  class NumberContext;
  class StringContext;
  class ListContext; 

  class  ChunkContext : public antlr4::ParserRuleContext {
  public:
    ChunkContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    antlr4::tree::TerminalNode *EOF();

   
  };

  ChunkContext* chunk();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatContext *> stat();
    StatContext* stat(size_t i);

   
  };

  BlockContext* block();

  class  StatContext : public antlr4::ParserRuleContext {
  public:
    StatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    TypeContext *type();
    ExplistContext *explist();
    OperatorMathAffectationContext *operatorMathAffectation();
    FunctioncallContext *functioncall();
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    FuncbodyContext *funcbody();
    ArgslistContext *argslist();
    StructbodyContext *structbody();
    GetstructmemberContext *getstructmember();

   
  };

  StatContext* stat();

  class  RetstatContext : public antlr4::ParserRuleContext {
  public:
    RetstatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpContext *exp();

   
  };

  RetstatContext* retstat();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();

   
  };

  TypeContext* type();

  class  ExplistContext : public antlr4::ParserRuleContext {
  public:
    ExplistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);

   
  };

  ExplistContext* explist();

  class  GetstructmemberContext : public antlr4::ParserRuleContext {
  public:
    GetstructmemberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    GetstructmemberContext *getstructmember();

   
  };

  GetstructmemberContext* getstructmember();

  class  FunctioncallContext : public antlr4::ParserRuleContext {
  public:
    FunctioncallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    GetstructmemberContext *getstructmember();
    std::vector<ExplistContext *> explist();
    ExplistContext* explist(size_t i);

   
  };

  FunctioncallContext* functioncall();

  class  ExpContext : public antlr4::ParserRuleContext {
  public:
    ExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumberContext *number();
    StringContext *string();
    ListContext *list();
    antlr4::tree::TerminalNode *NAME();
    FunctioncallContext *functioncall();
    GetstructmemberContext *getstructmember();
    OperatorUnaryContext *operatorUnary();
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);
    OperatorPowerContext *operatorPower();
    OperatorMulDivModContext *operatorMulDivMod();
    OperatorAddSubContext *operatorAddSub();
    OperatorStrcatContext *operatorStrcat();
    OperatorComparisonContext *operatorComparison();
    OperatorAndContext *operatorAnd();
    OperatorOrContext *operatorOr();
    OperatorBitwiseContext *operatorBitwise();

   
  };

  ExpContext* exp();
  ExpContext* exp(int precedence);
  class  ArgslistContext : public antlr4::ParserRuleContext {
  public:
    ArgslistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);

   
  };

  ArgslistContext* argslist();

  class  FuncbodyContext : public antlr4::ParserRuleContext {
  public:
    FuncbodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    RetstatContext *retstat();

   
  };

  FuncbodyContext* funcbody();

  class  StructbodyContext : public antlr4::ParserRuleContext {
  public:
    StructbodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();

   
  };

  StructbodyContext* structbody();

  class  OperatorOrContext : public antlr4::ParserRuleContext {
  public:
    OperatorOrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  OperatorOrContext* operatorOr();

  class  OperatorAndContext : public antlr4::ParserRuleContext {
  public:
    OperatorAndContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  OperatorAndContext* operatorAnd();

  class  OperatorComparisonContext : public antlr4::ParserRuleContext {
  public:
    OperatorComparisonContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  OperatorComparisonContext* operatorComparison();

  class  OperatorStrcatContext : public antlr4::ParserRuleContext {
  public:
    OperatorStrcatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  OperatorStrcatContext* operatorStrcat();

  class  OperatorAddSubContext : public antlr4::ParserRuleContext {
  public:
    OperatorAddSubContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  OperatorAddSubContext* operatorAddSub();

  class  OperatorMulDivModContext : public antlr4::ParserRuleContext {
  public:
    OperatorMulDivModContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  OperatorMulDivModContext* operatorMulDivMod();

  class  OperatorBitwiseContext : public antlr4::ParserRuleContext {
  public:
    OperatorBitwiseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  OperatorBitwiseContext* operatorBitwise();

  class  OperatorUnaryContext : public antlr4::ParserRuleContext {
  public:
    OperatorUnaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  OperatorUnaryContext* operatorUnary();

  class  OperatorPowerContext : public antlr4::ParserRuleContext {
  public:
    OperatorPowerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  OperatorPowerContext* operatorPower();

  class  OperatorMathAffectationContext : public antlr4::ParserRuleContext {
  public:
    OperatorMathAffectationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  OperatorMathAffectationContext* operatorMathAffectation();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *HEX();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *HEX_FLOAT();

   
  };

  NumberContext* number();

  class  StringContext : public antlr4::ParserRuleContext {
  public:
    StringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NORMALSTRING();
    antlr4::tree::TerminalNode *CHARSTRING();

   
  };

  StringContext* string();

  class  ListContext : public antlr4::ParserRuleContext {
  public:
    ListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExplistContext *explist();

   
  };

  ListContext* list();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expSempred(ExpContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace kafe
