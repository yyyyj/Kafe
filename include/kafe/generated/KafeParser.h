
#ifdef _MSC_VER
    // if compiling with visual studio, disable those warnings
    #pragma warning (disable: 4251)  // need a dll to run
    #pragma warning (disable: 4996)  // warnings from codecvt
#endif


// Generated from grammar/Kafe.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




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
    T__62 = 63, T__63 = 64, T__64 = 65, T__65 = 66, T__66 = 67, NAME = 68, 
    NORMALSTRING = 69, CHARSTRING = 70, INT = 71, HEX = 72, FLOAT = 73, 
    HEX_FLOAT = 74, COMMENT = 75, WS = 76
  };

  enum {
    RuleChunk = 0, RuleBlock = 1, RuleStat = 2, RuleRetstat = 3, RuleVarqualifier = 4, 
    RuleType = 5, RuleNamelist = 6, RuleExplist = 7, RuleGetstructmember = 8, 
    RuleFunctioncall = 9, RuleExp = 10, RuleArgslist = 11, RuleFuncbody = 12, 
    RuleStructparents = 13, RuleStructbody = 14, RuleOperatorOr = 15, RuleOperatorAnd = 16, 
    RuleOperatorComparison = 17, RuleOperatorStrcat = 18, RuleOperatorAddSub = 19, 
    RuleOperatorMulDivMod = 20, RuleOperatorBitwise = 21, RuleOperatorUnary = 22, 
    RuleOperatorPower = 23, RuleOperatorMathAffectation = 24, RuleNumber = 25, 
    RuleString = 26, RuleList = 27
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
  class VarqualifierContext;
  class TypeContext;
  class NamelistContext;
  class ExplistContext;
  class GetstructmemberContext;
  class FunctioncallContext;
  class ExpContext;
  class ArgslistContext;
  class FuncbodyContext;
  class StructparentsContext;
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

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ChunkContext* chunk();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatContext *> stat();
    StatContext* stat(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  StatContext : public antlr4::ParserRuleContext {
  public:
    StatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarqualifierContext *varqualifier();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    std::vector<ExplistContext *> explist();
    ExplistContext* explist(size_t i);
    NamelistContext *namelist();
    OperatorMathAffectationContext *operatorMathAffectation();
    FunctioncallContext *functioncall();
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    ArgslistContext *argslist();
    TypeContext *type();
    FuncbodyContext *funcbody();
    StructbodyContext *structbody();
    StructparentsContext *structparents();
    GetstructmemberContext *getstructmember();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatContext* stat();

  class  RetstatContext : public antlr4::ParserRuleContext {
  public:
    RetstatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpContext *exp();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RetstatContext* retstat();

  class  VarqualifierContext : public antlr4::ParserRuleContext {
  public:
    VarqualifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarqualifierContext* varqualifier();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  NamelistContext : public antlr4::ParserRuleContext {
  public:
    NamelistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NamelistContext* namelist();

  class  ExplistContext : public antlr4::ParserRuleContext {
  public:
    ExplistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExplistContext* explist();

  class  GetstructmemberContext : public antlr4::ParserRuleContext {
  public:
    GetstructmemberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    GetstructmemberContext *getstructmember();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgslistContext* argslist();

  class  FuncbodyContext : public antlr4::ParserRuleContext {
  public:
    FuncbodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    RetstatContext *retstat();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncbodyContext* funcbody();

  class  StructparentsContext : public antlr4::ParserRuleContext {
  public:
    StructparentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructparentsContext* structparents();

  class  StructbodyContext : public antlr4::ParserRuleContext {
  public:
    StructbodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructbodyContext* structbody();

  class  OperatorOrContext : public antlr4::ParserRuleContext {
  public:
    OperatorOrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperatorOrContext* operatorOr();

  class  OperatorAndContext : public antlr4::ParserRuleContext {
  public:
    OperatorAndContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperatorAndContext* operatorAnd();

  class  OperatorComparisonContext : public antlr4::ParserRuleContext {
  public:
    OperatorComparisonContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperatorComparisonContext* operatorComparison();

  class  OperatorStrcatContext : public antlr4::ParserRuleContext {
  public:
    OperatorStrcatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperatorStrcatContext* operatorStrcat();

  class  OperatorAddSubContext : public antlr4::ParserRuleContext {
  public:
    OperatorAddSubContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperatorAddSubContext* operatorAddSub();

  class  OperatorMulDivModContext : public antlr4::ParserRuleContext {
  public:
    OperatorMulDivModContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperatorMulDivModContext* operatorMulDivMod();

  class  OperatorBitwiseContext : public antlr4::ParserRuleContext {
  public:
    OperatorBitwiseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperatorBitwiseContext* operatorBitwise();

  class  OperatorUnaryContext : public antlr4::ParserRuleContext {
  public:
    OperatorUnaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperatorUnaryContext* operatorUnary();

  class  OperatorPowerContext : public antlr4::ParserRuleContext {
  public:
    OperatorPowerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperatorPowerContext* operatorPower();

  class  OperatorMathAffectationContext : public antlr4::ParserRuleContext {
  public:
    OperatorMathAffectationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberContext* number();

  class  StringContext : public antlr4::ParserRuleContext {
  public:
    StringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NORMALSTRING();
    antlr4::tree::TerminalNode *CHARSTRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StringContext* string();

  class  ListContext : public antlr4::ParserRuleContext {
  public:
    ListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExplistContext *explist();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

