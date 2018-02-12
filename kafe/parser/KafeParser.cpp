
// Generated from Kafe.g by ANTLR 4.7.1


#include "KafeListener.h"
#include "KafeVisitor.h"

#include "KafeParser.h"


using namespace antlrcpp;
using namespace Kafe;
using namespace antlr4;

KafeParser::KafeParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

KafeParser::~KafeParser() {
  delete _interpreter;
}

std::string KafeParser::getGrammarFileName() const {
  return "Kafe.g";
}

const std::vector<std::string>& KafeParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& KafeParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ChunkContext ------------------------------------------------------------------

KafeParser::ChunkContext::ChunkContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KafeParser::BlockContext* KafeParser::ChunkContext::block() {
  return getRuleContext<KafeParser::BlockContext>(0);
}

tree::TerminalNode* KafeParser::ChunkContext::EOF() {
  return getToken(KafeParser::EOF, 0);
}


size_t KafeParser::ChunkContext::getRuleIndex() const {
  return KafeParser::RuleChunk;
}

void KafeParser::ChunkContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChunk(this);
}

void KafeParser::ChunkContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChunk(this);
}


antlrcpp::Any KafeParser::ChunkContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitChunk(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::ChunkContext* KafeParser::chunk() {
  ChunkContext *_localctx = _tracker.createInstance<ChunkContext>(_ctx, getState());
  enterRule(_localctx, 0, KafeParser::RuleChunk);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(46);
    block();
    setState(47);
    match(KafeParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

KafeParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<KafeParser::StatContext *> KafeParser::BlockContext::stat() {
  return getRuleContexts<KafeParser::StatContext>();
}

KafeParser::StatContext* KafeParser::BlockContext::stat(size_t i) {
  return getRuleContext<KafeParser::StatContext>(i);
}


size_t KafeParser::BlockContext::getRuleIndex() const {
  return KafeParser::RuleBlock;
}

void KafeParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void KafeParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


antlrcpp::Any KafeParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::BlockContext* KafeParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 2, KafeParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(52);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << KafeParser::T__0)
      | (1ULL << KafeParser::T__3)
      | (1ULL << KafeParser::T__7)
      | (1ULL << KafeParser::T__11)
      | (1ULL << KafeParser::T__12)
      | (1ULL << KafeParser::T__13)
      | (1ULL << KafeParser::T__20)
      | (1ULL << KafeParser::NAME))) != 0)) {
      setState(49);
      stat();
      setState(54);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatContext ------------------------------------------------------------------

KafeParser::StatContext::StatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KafeParser::StatContext::NAME() {
  return getToken(KafeParser::NAME, 0);
}

KafeParser::TypeContext* KafeParser::StatContext::type() {
  return getRuleContext<KafeParser::TypeContext>(0);
}

KafeParser::ExplistContext* KafeParser::StatContext::explist() {
  return getRuleContext<KafeParser::ExplistContext>(0);
}

KafeParser::FunctioncallContext* KafeParser::StatContext::functioncall() {
  return getRuleContext<KafeParser::FunctioncallContext>(0);
}

std::vector<KafeParser::ExpContext *> KafeParser::StatContext::exp() {
  return getRuleContexts<KafeParser::ExpContext>();
}

KafeParser::ExpContext* KafeParser::StatContext::exp(size_t i) {
  return getRuleContext<KafeParser::ExpContext>(i);
}

std::vector<KafeParser::BlockContext *> KafeParser::StatContext::block() {
  return getRuleContexts<KafeParser::BlockContext>();
}

KafeParser::BlockContext* KafeParser::StatContext::block(size_t i) {
  return getRuleContext<KafeParser::BlockContext>(i);
}

KafeParser::FuncbodyContext* KafeParser::StatContext::funcbody() {
  return getRuleContext<KafeParser::FuncbodyContext>(0);
}

KafeParser::ArgslistContext* KafeParser::StatContext::argslist() {
  return getRuleContext<KafeParser::ArgslistContext>(0);
}

KafeParser::StructbodyContext* KafeParser::StatContext::structbody() {
  return getRuleContext<KafeParser::StructbodyContext>(0);
}


size_t KafeParser::StatContext::getRuleIndex() const {
  return KafeParser::RuleStat;
}

void KafeParser::StatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStat(this);
}

void KafeParser::StatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStat(this);
}


antlrcpp::Any KafeParser::StatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitStat(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::StatContext* KafeParser::stat() {
  StatContext *_localctx = _tracker.createInstance<StatContext>(_ctx, getState());
  enterRule(_localctx, 4, KafeParser::RuleStat);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(115);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case KafeParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(55);
        match(KafeParser::T__0);
        setState(56);
        match(KafeParser::NAME);
        setState(57);
        match(KafeParser::T__1);
        setState(58);
        type();
        setState(59);
        match(KafeParser::T__2);
        setState(60);
        explist();
        break;
      }

      case KafeParser::NAME: {
        enterOuterAlt(_localctx, 2);
        setState(62);
        match(KafeParser::NAME);
        setState(63);
        match(KafeParser::T__2);
        setState(64);
        explist();
        break;
      }

      case KafeParser::T__20: {
        enterOuterAlt(_localctx, 3);
        setState(65);
        functioncall();
        break;
      }

      case KafeParser::T__3: {
        enterOuterAlt(_localctx, 4);
        setState(66);
        match(KafeParser::T__3);
        setState(67);
        match(KafeParser::NAME);
        setState(68);
        match(KafeParser::T__4);
        setState(69);
        exp(0);
        setState(70);
        match(KafeParser::T__5);
        setState(71);
        block();
        setState(72);
        match(KafeParser::T__6);
        break;
      }

      case KafeParser::T__7: {
        enterOuterAlt(_localctx, 5);
        setState(74);
        match(KafeParser::T__7);
        setState(75);
        exp(0);
        setState(76);
        match(KafeParser::T__8);
        setState(77);
        block();
        setState(85);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == KafeParser::T__9) {
          setState(78);
          match(KafeParser::T__9);
          setState(79);
          exp(0);
          setState(80);
          match(KafeParser::T__8);
          setState(81);
          block();
          setState(87);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(90);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == KafeParser::T__10) {
          setState(88);
          match(KafeParser::T__10);
          setState(89);
          block();
        }
        setState(92);
        match(KafeParser::T__6);
        break;
      }

      case KafeParser::T__11: {
        enterOuterAlt(_localctx, 6);
        setState(94);
        match(KafeParser::T__11);
        setState(95);
        exp(0);
        setState(96);
        match(KafeParser::T__5);
        setState(97);
        block();
        setState(98);
        match(KafeParser::T__6);
        break;
      }

      case KafeParser::T__12: {
        enterOuterAlt(_localctx, 7);
        setState(100);
        match(KafeParser::T__12);
        setState(101);
        match(KafeParser::NAME);
        setState(102);
        match(KafeParser::T__1);
        setState(103);
        type();
        setState(105);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == KafeParser::T__25) {
          setState(104);
          argslist();
        }
        setState(107);
        funcbody();
        break;
      }

      case KafeParser::T__13: {
        enterOuterAlt(_localctx, 8);
        setState(109);
        match(KafeParser::T__13);
        setState(110);
        match(KafeParser::NAME);
        setState(112);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == KafeParser::T__25) {
          setState(111);
          argslist();
        }
        setState(114);
        structbody();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RetstatContext ------------------------------------------------------------------

KafeParser::RetstatContext::RetstatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KafeParser::ExpContext* KafeParser::RetstatContext::exp() {
  return getRuleContext<KafeParser::ExpContext>(0);
}


size_t KafeParser::RetstatContext::getRuleIndex() const {
  return KafeParser::RuleRetstat;
}

void KafeParser::RetstatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRetstat(this);
}

void KafeParser::RetstatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRetstat(this);
}


antlrcpp::Any KafeParser::RetstatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitRetstat(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::RetstatContext* KafeParser::retstat() {
  RetstatContext *_localctx = _tracker.createInstance<RetstatContext>(_ctx, getState());
  enterRule(_localctx, 6, KafeParser::RuleRetstat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(117);
    match(KafeParser::T__14);
    setState(118);
    exp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

KafeParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KafeParser::TypeContext::NAME() {
  return getToken(KafeParser::NAME, 0);
}


size_t KafeParser::TypeContext::getRuleIndex() const {
  return KafeParser::RuleType;
}

void KafeParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void KafeParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


antlrcpp::Any KafeParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::TypeContext* KafeParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 8, KafeParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(127);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case KafeParser::T__15: {
        enterOuterAlt(_localctx, 1);
        setState(120);
        match(KafeParser::T__15);
        break;
      }

      case KafeParser::T__16: {
        enterOuterAlt(_localctx, 2);
        setState(121);
        match(KafeParser::T__16);
        break;
      }

      case KafeParser::T__17: {
        enterOuterAlt(_localctx, 3);
        setState(122);
        match(KafeParser::T__17);
        break;
      }

      case KafeParser::T__18: {
        enterOuterAlt(_localctx, 4);
        setState(123);
        match(KafeParser::T__18);
        break;
      }

      case KafeParser::T__19: {
        enterOuterAlt(_localctx, 5);
        setState(124);
        match(KafeParser::T__19);
        break;
      }

      case KafeParser::T__13: {
        enterOuterAlt(_localctx, 6);
        setState(125);
        match(KafeParser::T__13);
        setState(126);
        match(KafeParser::NAME);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExplistContext ------------------------------------------------------------------

KafeParser::ExplistContext::ExplistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<KafeParser::ExpContext *> KafeParser::ExplistContext::exp() {
  return getRuleContexts<KafeParser::ExpContext>();
}

KafeParser::ExpContext* KafeParser::ExplistContext::exp(size_t i) {
  return getRuleContext<KafeParser::ExpContext>(i);
}


size_t KafeParser::ExplistContext::getRuleIndex() const {
  return KafeParser::RuleExplist;
}

void KafeParser::ExplistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExplist(this);
}

void KafeParser::ExplistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExplist(this);
}


antlrcpp::Any KafeParser::ExplistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitExplist(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::ExplistContext* KafeParser::explist() {
  ExplistContext *_localctx = _tracker.createInstance<ExplistContext>(_ctx, getState());
  enterRule(_localctx, 10, KafeParser::RuleExplist);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(129);
    exp(0);
    setState(133);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(130);
        exp(0); 
      }
      setState(135);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctioncallContext ------------------------------------------------------------------

KafeParser::FunctioncallContext::FunctioncallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KafeParser::FunctioncallContext::NAME() {
  return getToken(KafeParser::NAME, 0);
}

std::vector<KafeParser::ExplistContext *> KafeParser::FunctioncallContext::explist() {
  return getRuleContexts<KafeParser::ExplistContext>();
}

KafeParser::ExplistContext* KafeParser::FunctioncallContext::explist(size_t i) {
  return getRuleContext<KafeParser::ExplistContext>(i);
}


size_t KafeParser::FunctioncallContext::getRuleIndex() const {
  return KafeParser::RuleFunctioncall;
}

void KafeParser::FunctioncallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctioncall(this);
}

void KafeParser::FunctioncallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctioncall(this);
}


antlrcpp::Any KafeParser::FunctioncallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitFunctioncall(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::FunctioncallContext* KafeParser::functioncall() {
  FunctioncallContext *_localctx = _tracker.createInstance<FunctioncallContext>(_ctx, getState());
  enterRule(_localctx, 12, KafeParser::RuleFunctioncall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(136);
    match(KafeParser::T__20);
    setState(137);
    match(KafeParser::NAME);
    setState(141);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << KafeParser::T__20)
      | (1ULL << KafeParser::T__22)
      | (1ULL << KafeParser::T__23)
      | (1ULL << KafeParser::T__24)
      | (1ULL << KafeParser::T__37)
      | (1ULL << KafeParser::T__44)
      | (1ULL << KafeParser::T__48)
      | (1ULL << KafeParser::T__50)
      | (1ULL << KafeParser::NORMALSTRING)
      | (1ULL << KafeParser::CHARSTRING)
      | (1ULL << KafeParser::INT)
      | (1ULL << KafeParser::HEX)
      | (1ULL << KafeParser::FLOAT)
      | (1ULL << KafeParser::HEX_FLOAT))) != 0)) {
      setState(138);
      explist();
      setState(143);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(144);
    match(KafeParser::T__21);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

KafeParser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KafeParser::NumberContext* KafeParser::ExpContext::number() {
  return getRuleContext<KafeParser::NumberContext>(0);
}

KafeParser::StringContext* KafeParser::ExpContext::string() {
  return getRuleContext<KafeParser::StringContext>(0);
}

KafeParser::ListContext* KafeParser::ExpContext::list() {
  return getRuleContext<KafeParser::ListContext>(0);
}

KafeParser::FunctioncallContext* KafeParser::ExpContext::functioncall() {
  return getRuleContext<KafeParser::FunctioncallContext>(0);
}

KafeParser::OperatorUnaryContext* KafeParser::ExpContext::operatorUnary() {
  return getRuleContext<KafeParser::OperatorUnaryContext>(0);
}

std::vector<KafeParser::ExpContext *> KafeParser::ExpContext::exp() {
  return getRuleContexts<KafeParser::ExpContext>();
}

KafeParser::ExpContext* KafeParser::ExpContext::exp(size_t i) {
  return getRuleContext<KafeParser::ExpContext>(i);
}

KafeParser::OperatorPowerContext* KafeParser::ExpContext::operatorPower() {
  return getRuleContext<KafeParser::OperatorPowerContext>(0);
}

KafeParser::OperatorMulDivModContext* KafeParser::ExpContext::operatorMulDivMod() {
  return getRuleContext<KafeParser::OperatorMulDivModContext>(0);
}

KafeParser::OperatorAddSubContext* KafeParser::ExpContext::operatorAddSub() {
  return getRuleContext<KafeParser::OperatorAddSubContext>(0);
}

KafeParser::OperatorStrcatContext* KafeParser::ExpContext::operatorStrcat() {
  return getRuleContext<KafeParser::OperatorStrcatContext>(0);
}

KafeParser::OperatorComparisonContext* KafeParser::ExpContext::operatorComparison() {
  return getRuleContext<KafeParser::OperatorComparisonContext>(0);
}

KafeParser::OperatorAndContext* KafeParser::ExpContext::operatorAnd() {
  return getRuleContext<KafeParser::OperatorAndContext>(0);
}

KafeParser::OperatorOrContext* KafeParser::ExpContext::operatorOr() {
  return getRuleContext<KafeParser::OperatorOrContext>(0);
}

KafeParser::OperatorBitwiseContext* KafeParser::ExpContext::operatorBitwise() {
  return getRuleContext<KafeParser::OperatorBitwiseContext>(0);
}


size_t KafeParser::ExpContext::getRuleIndex() const {
  return KafeParser::RuleExp;
}

void KafeParser::ExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExp(this);
}

void KafeParser::ExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExp(this);
}


antlrcpp::Any KafeParser::ExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitExp(this);
  else
    return visitor->visitChildren(this);
}


KafeParser::ExpContext* KafeParser::exp() {
   return exp(0);
}

KafeParser::ExpContext* KafeParser::exp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  KafeParser::ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, parentState);
  KafeParser::ExpContext *previousContext = _localctx;
  size_t startState = 14;
  enterRecursionRule(_localctx, 14, KafeParser::RuleExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(157);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case KafeParser::T__22: {
        setState(147);
        match(KafeParser::T__22);
        break;
      }

      case KafeParser::T__23: {
        setState(148);
        match(KafeParser::T__23);
        break;
      }

      case KafeParser::T__24: {
        setState(149);
        match(KafeParser::T__24);
        break;
      }

      case KafeParser::INT:
      case KafeParser::HEX:
      case KafeParser::FLOAT:
      case KafeParser::HEX_FLOAT: {
        setState(150);
        number();
        break;
      }

      case KafeParser::NORMALSTRING:
      case KafeParser::CHARSTRING: {
        setState(151);
        string();
        break;
      }

      case KafeParser::T__50: {
        setState(152);
        list();
        break;
      }

      case KafeParser::T__20: {
        setState(153);
        functioncall();
        break;
      }

      case KafeParser::T__37:
      case KafeParser::T__44:
      case KafeParser::T__48: {
        setState(154);
        operatorUnary();
        setState(155);
        exp(8);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(193);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(191);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(159);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(160);
          operatorPower();
          setState(161);
          exp(9);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(163);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(164);
          operatorMulDivMod();
          setState(165);
          exp(8);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(167);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(168);
          operatorAddSub();
          setState(169);
          exp(7);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(171);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(172);
          operatorStrcat();
          setState(173);
          exp(5);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(175);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(176);
          operatorComparison();
          setState(177);
          exp(5);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(179);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(180);
          operatorAnd();
          setState(181);
          exp(4);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(183);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(184);
          operatorOr();
          setState(185);
          exp(3);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(187);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(188);
          operatorBitwise();
          setState(189);
          exp(2);
          break;
        }

        } 
      }
      setState(195);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ArgslistContext ------------------------------------------------------------------

KafeParser::ArgslistContext::ArgslistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> KafeParser::ArgslistContext::NAME() {
  return getTokens(KafeParser::NAME);
}

tree::TerminalNode* KafeParser::ArgslistContext::NAME(size_t i) {
  return getToken(KafeParser::NAME, i);
}

std::vector<KafeParser::TypeContext *> KafeParser::ArgslistContext::type() {
  return getRuleContexts<KafeParser::TypeContext>();
}

KafeParser::TypeContext* KafeParser::ArgslistContext::type(size_t i) {
  return getRuleContext<KafeParser::TypeContext>(i);
}


size_t KafeParser::ArgslistContext::getRuleIndex() const {
  return KafeParser::RuleArgslist;
}

void KafeParser::ArgslistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgslist(this);
}

void KafeParser::ArgslistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgslist(this);
}


antlrcpp::Any KafeParser::ArgslistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitArgslist(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::ArgslistContext* KafeParser::argslist() {
  ArgslistContext *_localctx = _tracker.createInstance<ArgslistContext>(_ctx, getState());
  enterRule(_localctx, 16, KafeParser::RuleArgslist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(196);
    match(KafeParser::T__25);
    setState(203); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(197);
              match(KafeParser::NAME);
              setState(198);
              match(KafeParser::T__1);
              setState(199);
              type();
              setState(201);
              _errHandler->sync(this);

              _la = _input->LA(1);
              if (_la == KafeParser::T__26) {
                setState(200);
                match(KafeParser::T__26);
              }
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(205); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncbodyContext ------------------------------------------------------------------

KafeParser::FuncbodyContext::FuncbodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KafeParser::BlockContext* KafeParser::FuncbodyContext::block() {
  return getRuleContext<KafeParser::BlockContext>(0);
}

KafeParser::RetstatContext* KafeParser::FuncbodyContext::retstat() {
  return getRuleContext<KafeParser::RetstatContext>(0);
}


size_t KafeParser::FuncbodyContext::getRuleIndex() const {
  return KafeParser::RuleFuncbody;
}

void KafeParser::FuncbodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncbody(this);
}

void KafeParser::FuncbodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncbody(this);
}


antlrcpp::Any KafeParser::FuncbodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitFuncbody(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::FuncbodyContext* KafeParser::funcbody() {
  FuncbodyContext *_localctx = _tracker.createInstance<FuncbodyContext>(_ctx, getState());
  enterRule(_localctx, 18, KafeParser::RuleFuncbody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(207);
    block();
    setState(208);
    retstat();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructbodyContext ------------------------------------------------------------------

KafeParser::StructbodyContext::StructbodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KafeParser::BlockContext* KafeParser::StructbodyContext::block() {
  return getRuleContext<KafeParser::BlockContext>(0);
}


size_t KafeParser::StructbodyContext::getRuleIndex() const {
  return KafeParser::RuleStructbody;
}

void KafeParser::StructbodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructbody(this);
}

void KafeParser::StructbodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructbody(this);
}


antlrcpp::Any KafeParser::StructbodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitStructbody(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::StructbodyContext* KafeParser::structbody() {
  StructbodyContext *_localctx = _tracker.createInstance<StructbodyContext>(_ctx, getState());
  enterRule(_localctx, 20, KafeParser::RuleStructbody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(210);
    block();
    setState(211);
    match(KafeParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperatorOrContext ------------------------------------------------------------------

KafeParser::OperatorOrContext::OperatorOrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t KafeParser::OperatorOrContext::getRuleIndex() const {
  return KafeParser::RuleOperatorOr;
}

void KafeParser::OperatorOrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperatorOr(this);
}

void KafeParser::OperatorOrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperatorOr(this);
}


antlrcpp::Any KafeParser::OperatorOrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitOperatorOr(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::OperatorOrContext* KafeParser::operatorOr() {
  OperatorOrContext *_localctx = _tracker.createInstance<OperatorOrContext>(_ctx, getState());
  enterRule(_localctx, 22, KafeParser::RuleOperatorOr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(213);
    match(KafeParser::T__27);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperatorAndContext ------------------------------------------------------------------

KafeParser::OperatorAndContext::OperatorAndContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t KafeParser::OperatorAndContext::getRuleIndex() const {
  return KafeParser::RuleOperatorAnd;
}

void KafeParser::OperatorAndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperatorAnd(this);
}

void KafeParser::OperatorAndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperatorAnd(this);
}


antlrcpp::Any KafeParser::OperatorAndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitOperatorAnd(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::OperatorAndContext* KafeParser::operatorAnd() {
  OperatorAndContext *_localctx = _tracker.createInstance<OperatorAndContext>(_ctx, getState());
  enterRule(_localctx, 24, KafeParser::RuleOperatorAnd);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    match(KafeParser::T__28);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperatorComparisonContext ------------------------------------------------------------------

KafeParser::OperatorComparisonContext::OperatorComparisonContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t KafeParser::OperatorComparisonContext::getRuleIndex() const {
  return KafeParser::RuleOperatorComparison;
}

void KafeParser::OperatorComparisonContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperatorComparison(this);
}

void KafeParser::OperatorComparisonContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperatorComparison(this);
}


antlrcpp::Any KafeParser::OperatorComparisonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitOperatorComparison(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::OperatorComparisonContext* KafeParser::operatorComparison() {
  OperatorComparisonContext *_localctx = _tracker.createInstance<OperatorComparisonContext>(_ctx, getState());
  enterRule(_localctx, 26, KafeParser::RuleOperatorComparison);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(217);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << KafeParser::T__29)
      | (1ULL << KafeParser::T__30)
      | (1ULL << KafeParser::T__31)
      | (1ULL << KafeParser::T__32)
      | (1ULL << KafeParser::T__33)
      | (1ULL << KafeParser::T__34))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperatorStrcatContext ------------------------------------------------------------------

KafeParser::OperatorStrcatContext::OperatorStrcatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t KafeParser::OperatorStrcatContext::getRuleIndex() const {
  return KafeParser::RuleOperatorStrcat;
}

void KafeParser::OperatorStrcatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperatorStrcat(this);
}

void KafeParser::OperatorStrcatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperatorStrcat(this);
}


antlrcpp::Any KafeParser::OperatorStrcatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitOperatorStrcat(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::OperatorStrcatContext* KafeParser::operatorStrcat() {
  OperatorStrcatContext *_localctx = _tracker.createInstance<OperatorStrcatContext>(_ctx, getState());
  enterRule(_localctx, 28, KafeParser::RuleOperatorStrcat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(219);
    match(KafeParser::T__35);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperatorAddSubContext ------------------------------------------------------------------

KafeParser::OperatorAddSubContext::OperatorAddSubContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t KafeParser::OperatorAddSubContext::getRuleIndex() const {
  return KafeParser::RuleOperatorAddSub;
}

void KafeParser::OperatorAddSubContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperatorAddSub(this);
}

void KafeParser::OperatorAddSubContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperatorAddSub(this);
}


antlrcpp::Any KafeParser::OperatorAddSubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitOperatorAddSub(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::OperatorAddSubContext* KafeParser::operatorAddSub() {
  OperatorAddSubContext *_localctx = _tracker.createInstance<OperatorAddSubContext>(_ctx, getState());
  enterRule(_localctx, 30, KafeParser::RuleOperatorAddSub);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(221);
    _la = _input->LA(1);
    if (!(_la == KafeParser::T__36

    || _la == KafeParser::T__37)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperatorMulDivModContext ------------------------------------------------------------------

KafeParser::OperatorMulDivModContext::OperatorMulDivModContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t KafeParser::OperatorMulDivModContext::getRuleIndex() const {
  return KafeParser::RuleOperatorMulDivMod;
}

void KafeParser::OperatorMulDivModContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperatorMulDivMod(this);
}

void KafeParser::OperatorMulDivModContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperatorMulDivMod(this);
}


antlrcpp::Any KafeParser::OperatorMulDivModContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitOperatorMulDivMod(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::OperatorMulDivModContext* KafeParser::operatorMulDivMod() {
  OperatorMulDivModContext *_localctx = _tracker.createInstance<OperatorMulDivModContext>(_ctx, getState());
  enterRule(_localctx, 32, KafeParser::RuleOperatorMulDivMod);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(223);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << KafeParser::T__38)
      | (1ULL << KafeParser::T__39)
      | (1ULL << KafeParser::T__40)
      | (1ULL << KafeParser::T__41))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperatorBitwiseContext ------------------------------------------------------------------

KafeParser::OperatorBitwiseContext::OperatorBitwiseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t KafeParser::OperatorBitwiseContext::getRuleIndex() const {
  return KafeParser::RuleOperatorBitwise;
}

void KafeParser::OperatorBitwiseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperatorBitwise(this);
}

void KafeParser::OperatorBitwiseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperatorBitwise(this);
}


antlrcpp::Any KafeParser::OperatorBitwiseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitOperatorBitwise(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::OperatorBitwiseContext* KafeParser::operatorBitwise() {
  OperatorBitwiseContext *_localctx = _tracker.createInstance<OperatorBitwiseContext>(_ctx, getState());
  enterRule(_localctx, 34, KafeParser::RuleOperatorBitwise);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(225);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << KafeParser::T__42)
      | (1ULL << KafeParser::T__43)
      | (1ULL << KafeParser::T__44)
      | (1ULL << KafeParser::T__45)
      | (1ULL << KafeParser::T__46)
      | (1ULL << KafeParser::T__47))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperatorUnaryContext ------------------------------------------------------------------

KafeParser::OperatorUnaryContext::OperatorUnaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t KafeParser::OperatorUnaryContext::getRuleIndex() const {
  return KafeParser::RuleOperatorUnary;
}

void KafeParser::OperatorUnaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperatorUnary(this);
}

void KafeParser::OperatorUnaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperatorUnary(this);
}


antlrcpp::Any KafeParser::OperatorUnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitOperatorUnary(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::OperatorUnaryContext* KafeParser::operatorUnary() {
  OperatorUnaryContext *_localctx = _tracker.createInstance<OperatorUnaryContext>(_ctx, getState());
  enterRule(_localctx, 36, KafeParser::RuleOperatorUnary);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(227);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << KafeParser::T__37)
      | (1ULL << KafeParser::T__44)
      | (1ULL << KafeParser::T__48))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperatorPowerContext ------------------------------------------------------------------

KafeParser::OperatorPowerContext::OperatorPowerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t KafeParser::OperatorPowerContext::getRuleIndex() const {
  return KafeParser::RuleOperatorPower;
}

void KafeParser::OperatorPowerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperatorPower(this);
}

void KafeParser::OperatorPowerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperatorPower(this);
}


antlrcpp::Any KafeParser::OperatorPowerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitOperatorPower(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::OperatorPowerContext* KafeParser::operatorPower() {
  OperatorPowerContext *_localctx = _tracker.createInstance<OperatorPowerContext>(_ctx, getState());
  enterRule(_localctx, 38, KafeParser::RuleOperatorPower);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(229);
    match(KafeParser::T__49);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

KafeParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KafeParser::NumberContext::INT() {
  return getToken(KafeParser::INT, 0);
}

tree::TerminalNode* KafeParser::NumberContext::HEX() {
  return getToken(KafeParser::HEX, 0);
}

tree::TerminalNode* KafeParser::NumberContext::FLOAT() {
  return getToken(KafeParser::FLOAT, 0);
}

tree::TerminalNode* KafeParser::NumberContext::HEX_FLOAT() {
  return getToken(KafeParser::HEX_FLOAT, 0);
}


size_t KafeParser::NumberContext::getRuleIndex() const {
  return KafeParser::RuleNumber;
}

void KafeParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void KafeParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}


antlrcpp::Any KafeParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::NumberContext* KafeParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 40, KafeParser::RuleNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(231);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << KafeParser::INT)
      | (1ULL << KafeParser::HEX)
      | (1ULL << KafeParser::FLOAT)
      | (1ULL << KafeParser::HEX_FLOAT))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringContext ------------------------------------------------------------------

KafeParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KafeParser::StringContext::NORMALSTRING() {
  return getToken(KafeParser::NORMALSTRING, 0);
}

tree::TerminalNode* KafeParser::StringContext::CHARSTRING() {
  return getToken(KafeParser::CHARSTRING, 0);
}


size_t KafeParser::StringContext::getRuleIndex() const {
  return KafeParser::RuleString;
}

void KafeParser::StringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString(this);
}

void KafeParser::StringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString(this);
}


antlrcpp::Any KafeParser::StringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::StringContext* KafeParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 42, KafeParser::RuleString);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(233);
    _la = _input->LA(1);
    if (!(_la == KafeParser::NORMALSTRING

    || _la == KafeParser::CHARSTRING)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ListContext ------------------------------------------------------------------

KafeParser::ListContext::ListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KafeParser::ExplistContext* KafeParser::ListContext::explist() {
  return getRuleContext<KafeParser::ExplistContext>(0);
}


size_t KafeParser::ListContext::getRuleIndex() const {
  return KafeParser::RuleList;
}

void KafeParser::ListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterList(this);
}

void KafeParser::ListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KafeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitList(this);
}


antlrcpp::Any KafeParser::ListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitList(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::ListContext* KafeParser::list() {
  ListContext *_localctx = _tracker.createInstance<ListContext>(_ctx, getState());
  enterRule(_localctx, 44, KafeParser::RuleList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(235);
    match(KafeParser::T__50);
    setState(236);
    explist();
    setState(237);
    match(KafeParser::T__51);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool KafeParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 7: return expSempred(dynamic_cast<ExpContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool KafeParser::expSempred(ExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 9);
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 6);
    case 3: return precpred(_ctx, 5);
    case 4: return precpred(_ctx, 4);
    case 5: return precpred(_ctx, 3);
    case 6: return precpred(_ctx, 2);
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> KafeParser::_decisionToDFA;
atn::PredictionContextCache KafeParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN KafeParser::_atn;
std::vector<uint16_t> KafeParser::_serializedATN;

std::vector<std::string> KafeParser::_ruleNames = {
  "chunk", "block", "stat", "retstat", "type", "explist", "functioncall", 
  "exp", "argslist", "funcbody", "structbody", "operatorOr", "operatorAnd", 
  "operatorComparison", "operatorStrcat", "operatorAddSub", "operatorMulDivMod", 
  "operatorBitwise", "operatorUnary", "operatorPower", "number", "string", 
  "list"
};

std::vector<std::string> KafeParser::_literalNames = {
  "", "'dyn'", "':'", "'='", "'for'", "'in'", "'do'", "'end'", "'if'", "'then'", 
  "'elif'", "'else'", "'while'", "'func'", "'struct'", "'ret'", "'string'", 
  "'int'", "'double'", "'list'", "'bool'", "'('", "')'", "'nil'", "'false'", 
  "'true'", "'--'", "','", "'or'", "'and'", "'<'", "'>'", "'<='", "'>='", 
  "'!='", "'=='", "'..'", "'+'", "'-'", "'*'", "'/'", "'%'", "'//'", "'&'", 
  "'|'", "'~'", "'<<'", "'>>'", "'^'", "'not'", "'**'", "'['", "']'"
};

std::vector<std::string> KafeParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "NAME", 
  "NORMALSTRING", "CHARSTRING", "INT", "HEX", "FLOAT", "HEX_FLOAT", "COMMENT", 
  "WS"
};

dfa::Vocabulary KafeParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> KafeParser::_tokenNames;

KafeParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x3f, 0xf2, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x7, 0x3, 0x35, 0xa, 0x3, 0xc, 
    0x3, 0xe, 0x3, 0x38, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x56, 0xa, 0x4, 0xc, 0x4, 0xe, 
    0x4, 0x59, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x5d, 0xa, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x6c, 
    0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
    0x73, 0xa, 0x4, 0x3, 0x4, 0x5, 0x4, 0x76, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x5, 0x6, 0x82, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x86, 
    0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x89, 0xb, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x7, 0x8, 0x8e, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x91, 0xb, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xa0, 
    0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0xc2, 0xa, 
    0x9, 0xc, 0x9, 0xe, 0x9, 0xc5, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xcc, 0xa, 0xa, 0x6, 0xa, 0xce, 0xa, 0xa, 
    0xd, 0xa, 0xe, 0xa, 0xcf, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x2, 0x3, 0x10, 0x19, 0x2, 0x4, 0x6, 0x8, 0xa, 
    0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
    0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x2, 0x9, 0x3, 0x2, 0x20, 0x25, 
    0x3, 0x2, 0x27, 0x28, 0x3, 0x2, 0x29, 0x2c, 0x3, 0x2, 0x2d, 0x32, 0x5, 
    0x2, 0x28, 0x28, 0x2f, 0x2f, 0x33, 0x33, 0x3, 0x2, 0x3a, 0x3d, 0x3, 
    0x2, 0x38, 0x39, 0x2, 0xfe, 0x2, 0x30, 0x3, 0x2, 0x2, 0x2, 0x4, 0x36, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x75, 0x3, 0x2, 0x2, 0x2, 0x8, 0x77, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x81, 0x3, 0x2, 0x2, 0x2, 0xc, 0x83, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x10, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0xc6, 0x3, 0x2, 0x2, 0x2, 0x14, 0xd1, 0x3, 0x2, 0x2, 0x2, 0x16, 0xd4, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xd9, 0x3, 
    0x2, 0x2, 0x2, 0x1c, 0xdb, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xdd, 0x3, 0x2, 
    0x2, 0x2, 0x20, 0xdf, 0x3, 0x2, 0x2, 0x2, 0x22, 0xe1, 0x3, 0x2, 0x2, 
    0x2, 0x24, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x26, 0xe5, 0x3, 0x2, 0x2, 0x2, 
    0x28, 0xe7, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xe9, 0x3, 0x2, 0x2, 0x2, 0x2c, 
    0xeb, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xed, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 
    0x5, 0x4, 0x3, 0x2, 0x31, 0x32, 0x7, 0x2, 0x2, 0x3, 0x32, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x33, 0x35, 0x5, 0x6, 0x4, 0x2, 0x34, 0x33, 0x3, 0x2, 
    0x2, 0x2, 0x35, 0x38, 0x3, 0x2, 0x2, 0x2, 0x36, 0x34, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x37, 0x3, 0x2, 0x2, 0x2, 0x37, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x38, 0x36, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x7, 0x3, 0x2, 0x2, 0x3a, 
    0x3b, 0x7, 0x37, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0x4, 0x2, 0x2, 0x3c, 0x3d, 
    0x5, 0xa, 0x6, 0x2, 0x3d, 0x3e, 0x7, 0x5, 0x2, 0x2, 0x3e, 0x3f, 0x5, 
    0xc, 0x7, 0x2, 0x3f, 0x76, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0x7, 0x37, 
    0x2, 0x2, 0x41, 0x42, 0x7, 0x5, 0x2, 0x2, 0x42, 0x76, 0x5, 0xc, 0x7, 
    0x2, 0x43, 0x76, 0x5, 0xe, 0x8, 0x2, 0x44, 0x45, 0x7, 0x6, 0x2, 0x2, 
    0x45, 0x46, 0x7, 0x37, 0x2, 0x2, 0x46, 0x47, 0x7, 0x7, 0x2, 0x2, 0x47, 
    0x48, 0x5, 0x10, 0x9, 0x2, 0x48, 0x49, 0x7, 0x8, 0x2, 0x2, 0x49, 0x4a, 
    0x5, 0x4, 0x3, 0x2, 0x4a, 0x4b, 0x7, 0x9, 0x2, 0x2, 0x4b, 0x76, 0x3, 
    0x2, 0x2, 0x2, 0x4c, 0x4d, 0x7, 0xa, 0x2, 0x2, 0x4d, 0x4e, 0x5, 0x10, 
    0x9, 0x2, 0x4e, 0x4f, 0x7, 0xb, 0x2, 0x2, 0x4f, 0x57, 0x5, 0x4, 0x3, 
    0x2, 0x50, 0x51, 0x7, 0xc, 0x2, 0x2, 0x51, 0x52, 0x5, 0x10, 0x9, 0x2, 
    0x52, 0x53, 0x7, 0xb, 0x2, 0x2, 0x53, 0x54, 0x5, 0x4, 0x3, 0x2, 0x54, 
    0x56, 0x3, 0x2, 0x2, 0x2, 0x55, 0x50, 0x3, 0x2, 0x2, 0x2, 0x56, 0x59, 
    0x3, 0x2, 0x2, 0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x3, 
    0x2, 0x2, 0x2, 0x58, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x59, 0x57, 0x3, 0x2, 
    0x2, 0x2, 0x5a, 0x5b, 0x7, 0xd, 0x2, 0x2, 0x5b, 0x5d, 0x5, 0x4, 0x3, 
    0x2, 0x5c, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x3, 0x2, 0x2, 0x2, 
    0x5d, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0x9, 0x2, 0x2, 0x5f, 
    0x76, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x7, 0xe, 0x2, 0x2, 0x61, 0x62, 
    0x5, 0x10, 0x9, 0x2, 0x62, 0x63, 0x7, 0x8, 0x2, 0x2, 0x63, 0x64, 0x5, 
    0x4, 0x3, 0x2, 0x64, 0x65, 0x7, 0x9, 0x2, 0x2, 0x65, 0x76, 0x3, 0x2, 
    0x2, 0x2, 0x66, 0x67, 0x7, 0xf, 0x2, 0x2, 0x67, 0x68, 0x7, 0x37, 0x2, 
    0x2, 0x68, 0x69, 0x7, 0x4, 0x2, 0x2, 0x69, 0x6b, 0x5, 0xa, 0x6, 0x2, 
    0x6a, 0x6c, 0x5, 0x12, 0xa, 0x2, 0x6b, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6b, 
    0x6c, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 
    0x5, 0x14, 0xb, 0x2, 0x6e, 0x76, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x7, 
    0x10, 0x2, 0x2, 0x70, 0x72, 0x7, 0x37, 0x2, 0x2, 0x71, 0x73, 0x5, 0x12, 
    0xa, 0x2, 0x72, 0x71, 0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 0x3, 0x2, 0x2, 
    0x2, 0x73, 0x74, 0x3, 0x2, 0x2, 0x2, 0x74, 0x76, 0x5, 0x16, 0xc, 0x2, 
    0x75, 0x39, 0x3, 0x2, 0x2, 0x2, 0x75, 0x40, 0x3, 0x2, 0x2, 0x2, 0x75, 
    0x43, 0x3, 0x2, 0x2, 0x2, 0x75, 0x44, 0x3, 0x2, 0x2, 0x2, 0x75, 0x4c, 
    0x3, 0x2, 0x2, 0x2, 0x75, 0x60, 0x3, 0x2, 0x2, 0x2, 0x75, 0x66, 0x3, 
    0x2, 0x2, 0x2, 0x75, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x76, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x77, 0x78, 0x7, 0x11, 0x2, 0x2, 0x78, 0x79, 0x5, 0x10, 0x9, 
    0x2, 0x79, 0x9, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x82, 0x7, 0x12, 0x2, 0x2, 
    0x7b, 0x82, 0x7, 0x13, 0x2, 0x2, 0x7c, 0x82, 0x7, 0x14, 0x2, 0x2, 0x7d, 
    0x82, 0x7, 0x15, 0x2, 0x2, 0x7e, 0x82, 0x7, 0x16, 0x2, 0x2, 0x7f, 0x80, 
    0x7, 0x10, 0x2, 0x2, 0x80, 0x82, 0x7, 0x37, 0x2, 0x2, 0x81, 0x7a, 0x3, 
    0x2, 0x2, 0x2, 0x81, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x81, 0x7c, 0x3, 0x2, 
    0x2, 0x2, 0x81, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x81, 0x7e, 0x3, 0x2, 0x2, 
    0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x82, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0x83, 0x87, 0x5, 0x10, 0x9, 0x2, 0x84, 0x86, 0x5, 0x10, 0x9, 0x2, 0x85, 
    0x84, 0x3, 0x2, 0x2, 0x2, 0x86, 0x89, 0x3, 0x2, 0x2, 0x2, 0x87, 0x85, 
    0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 0x3, 0x2, 0x2, 0x2, 0x88, 0xd, 0x3, 
    0x2, 0x2, 0x2, 0x89, 0x87, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x7, 0x17, 
    0x2, 0x2, 0x8b, 0x8f, 0x7, 0x37, 0x2, 0x2, 0x8c, 0x8e, 0x5, 0xc, 0x7, 
    0x2, 0x8d, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x91, 0x3, 0x2, 0x2, 0x2, 
    0x8f, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x3, 0x2, 0x2, 0x2, 0x90, 
    0x92, 0x3, 0x2, 0x2, 0x2, 0x91, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 
    0x7, 0x18, 0x2, 0x2, 0x93, 0xf, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x8, 
    0x9, 0x1, 0x2, 0x95, 0xa0, 0x7, 0x19, 0x2, 0x2, 0x96, 0xa0, 0x7, 0x1a, 
    0x2, 0x2, 0x97, 0xa0, 0x7, 0x1b, 0x2, 0x2, 0x98, 0xa0, 0x5, 0x2a, 0x16, 
    0x2, 0x99, 0xa0, 0x5, 0x2c, 0x17, 0x2, 0x9a, 0xa0, 0x5, 0x2e, 0x18, 
    0x2, 0x9b, 0xa0, 0x5, 0xe, 0x8, 0x2, 0x9c, 0x9d, 0x5, 0x26, 0x14, 0x2, 
    0x9d, 0x9e, 0x5, 0x10, 0x9, 0xa, 0x9e, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x9f, 
    0x94, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x96, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x97, 
    0x3, 0x2, 0x2, 0x2, 0x9f, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x99, 0x3, 
    0x2, 0x2, 0x2, 0x9f, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x9b, 0x3, 0x2, 
    0x2, 0x2, 0x9f, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xc3, 0x3, 0x2, 0x2, 
    0x2, 0xa1, 0xa2, 0xc, 0xb, 0x2, 0x2, 0xa2, 0xa3, 0x5, 0x28, 0x15, 0x2, 
    0xa3, 0xa4, 0x5, 0x10, 0x9, 0xb, 0xa4, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xa5, 
    0xa6, 0xc, 0x9, 0x2, 0x2, 0xa6, 0xa7, 0x5, 0x22, 0x12, 0x2, 0xa7, 0xa8, 
    0x5, 0x10, 0x9, 0xa, 0xa8, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0xc, 
    0x8, 0x2, 0x2, 0xaa, 0xab, 0x5, 0x20, 0x11, 0x2, 0xab, 0xac, 0x5, 0x10, 
    0x9, 0x9, 0xac, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0xc, 0x7, 0x2, 
    0x2, 0xae, 0xaf, 0x5, 0x1e, 0x10, 0x2, 0xaf, 0xb0, 0x5, 0x10, 0x9, 0x7, 
    0xb0, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0xc, 0x6, 0x2, 0x2, 0xb2, 
    0xb3, 0x5, 0x1c, 0xf, 0x2, 0xb3, 0xb4, 0x5, 0x10, 0x9, 0x7, 0xb4, 0xc2, 
    0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0xc, 0x5, 0x2, 0x2, 0xb6, 0xb7, 0x5, 
    0x1a, 0xe, 0x2, 0xb7, 0xb8, 0x5, 0x10, 0x9, 0x6, 0xb8, 0xc2, 0x3, 0x2, 
    0x2, 0x2, 0xb9, 0xba, 0xc, 0x4, 0x2, 0x2, 0xba, 0xbb, 0x5, 0x18, 0xd, 
    0x2, 0xbb, 0xbc, 0x5, 0x10, 0x9, 0x5, 0xbc, 0xc2, 0x3, 0x2, 0x2, 0x2, 
    0xbd, 0xbe, 0xc, 0x3, 0x2, 0x2, 0xbe, 0xbf, 0x5, 0x24, 0x13, 0x2, 0xbf, 
    0xc0, 0x5, 0x10, 0x9, 0x4, 0xc0, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xa1, 
    0x3, 0x2, 0x2, 0x2, 0xc1, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xa9, 0x3, 
    0x2, 0x2, 0x2, 0xc1, 0xad, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xb1, 0x3, 0x2, 
    0x2, 0x2, 0xc1, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xb9, 0x3, 0x2, 0x2, 
    0x2, 0xc1, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc5, 0x3, 0x2, 0x2, 0x2, 
    0xc3, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc4, 
    0x11, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xcd, 
    0x7, 0x1c, 0x2, 0x2, 0xc7, 0xc8, 0x7, 0x37, 0x2, 0x2, 0xc8, 0xc9, 0x7, 
    0x4, 0x2, 0x2, 0xc9, 0xcb, 0x5, 0xa, 0x6, 0x2, 0xca, 0xcc, 0x7, 0x1d, 
    0x2, 0x2, 0xcb, 0xca, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x3, 0x2, 0x2, 
    0x2, 0xcc, 0xce, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xc7, 0x3, 0x2, 0x2, 0x2, 
    0xce, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcf, 
    0xd0, 0x3, 0x2, 0x2, 0x2, 0xd0, 0x13, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 
    0x5, 0x4, 0x3, 0x2, 0xd2, 0xd3, 0x5, 0x8, 0x5, 0x2, 0xd3, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0xd4, 0xd5, 0x5, 0x4, 0x3, 0x2, 0xd5, 0xd6, 0x7, 0x9, 
    0x2, 0x2, 0xd6, 0x17, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0x7, 0x1e, 0x2, 
    0x2, 0xd8, 0x19, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0x7, 0x1f, 0x2, 0x2, 
    0xda, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x9, 0x2, 0x2, 0x2, 0xdc, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 0x7, 0x26, 0x2, 0x2, 0xde, 0x1f, 
    0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x9, 0x3, 0x2, 0x2, 0xe0, 0x21, 0x3, 
    0x2, 0x2, 0x2, 0xe1, 0xe2, 0x9, 0x4, 0x2, 0x2, 0xe2, 0x23, 0x3, 0x2, 
    0x2, 0x2, 0xe3, 0xe4, 0x9, 0x5, 0x2, 0x2, 0xe4, 0x25, 0x3, 0x2, 0x2, 
    0x2, 0xe5, 0xe6, 0x9, 0x6, 0x2, 0x2, 0xe6, 0x27, 0x3, 0x2, 0x2, 0x2, 
    0xe7, 0xe8, 0x7, 0x34, 0x2, 0x2, 0xe8, 0x29, 0x3, 0x2, 0x2, 0x2, 0xe9, 
    0xea, 0x9, 0x7, 0x2, 0x2, 0xea, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 
    0x9, 0x8, 0x2, 0x2, 0xec, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xed, 0xee, 0x7, 
    0x35, 0x2, 0x2, 0xee, 0xef, 0x5, 0xc, 0x7, 0x2, 0xef, 0xf0, 0x7, 0x36, 
    0x2, 0x2, 0xf0, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x10, 0x36, 0x57, 0x5c, 0x6b, 
    0x72, 0x75, 0x81, 0x87, 0x8f, 0x9f, 0xc1, 0xc3, 0xcb, 0xcf, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

KafeParser::Initializer KafeParser::_init;
