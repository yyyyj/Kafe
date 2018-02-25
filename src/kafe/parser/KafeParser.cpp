
// Generated from Kafe.g by ANTLR 4.7.1



#include "KafeParser.h"


using namespace antlrcpp;
using namespace kafe;
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


KafeParser::ChunkContext* KafeParser::chunk() {
  ChunkContext *_localctx = _tracker.createInstance<ChunkContext>(_ctx, getState());
  enterRule(_localctx, 0, KafeParser::RuleChunk);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(52);
    block();
    setState(53);
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


KafeParser::BlockContext* KafeParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 2, KafeParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << KafeParser::T__2)
      | (1ULL << KafeParser::T__6)
      | (1ULL << KafeParser::T__10)
      | (1ULL << KafeParser::T__11)
      | (1ULL << KafeParser::T__12)
      | (1ULL << KafeParser::T__14)
      | (1ULL << KafeParser::T__15))) != 0) || _la == KafeParser::NAME) {
      setState(55);
      stat();
      setState(60);
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

KafeParser::VarqualifierContext* KafeParser::StatContext::varqualifier() {
  return getRuleContext<KafeParser::VarqualifierContext>(0);
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

KafeParser::OperatorMathAffectationContext* KafeParser::StatContext::operatorMathAffectation() {
  return getRuleContext<KafeParser::OperatorMathAffectationContext>(0);
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

KafeParser::GetstructmemberContext* KafeParser::StatContext::getstructmember() {
  return getRuleContext<KafeParser::GetstructmemberContext>(0);
}


size_t KafeParser::StatContext::getRuleIndex() const {
  return KafeParser::RuleStat;
}


KafeParser::StatContext* KafeParser::stat() {
  StatContext *_localctx = _tracker.createInstance<StatContext>(_ctx, getState());
  enterRule(_localctx, 4, KafeParser::RuleStat);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(126);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(61);
      varqualifier();
      setState(62);
      match(KafeParser::NAME);
      setState(63);
      match(KafeParser::T__0);
      setState(64);
      type();
      setState(65);
      match(KafeParser::T__1);
      setState(66);
      explist();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(68);
      match(KafeParser::NAME);
      setState(69);
      match(KafeParser::T__1);
      setState(70);
      explist();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(71);
      match(KafeParser::NAME);
      setState(72);
      operatorMathAffectation();
      setState(73);
      explist();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(75);
      functioncall();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(76);
      match(KafeParser::T__2);
      setState(77);
      match(KafeParser::NAME);
      setState(78);
      match(KafeParser::T__3);
      setState(79);
      exp(0);
      setState(80);
      match(KafeParser::T__4);
      setState(81);
      block();
      setState(82);
      match(KafeParser::T__5);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(84);
      match(KafeParser::T__6);
      setState(85);
      exp(0);
      setState(86);
      match(KafeParser::T__7);
      setState(87);
      block();
      setState(95);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == KafeParser::T__8) {
        setState(88);
        match(KafeParser::T__8);
        setState(89);
        exp(0);
        setState(90);
        match(KafeParser::T__7);
        setState(91);
        block();
        setState(97);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(100);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == KafeParser::T__9) {
        setState(98);
        match(KafeParser::T__9);
        setState(99);
        block();
      }
      setState(102);
      match(KafeParser::T__5);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(104);
      match(KafeParser::T__10);
      setState(105);
      exp(0);
      setState(106);
      match(KafeParser::T__4);
      setState(107);
      block();
      setState(108);
      match(KafeParser::T__5);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(110);
      match(KafeParser::T__11);
      setState(111);
      match(KafeParser::NAME);
      setState(112);
      match(KafeParser::T__0);
      setState(113);
      type();
      setState(115);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == KafeParser::T__27) {
        setState(114);
        argslist();
      }
      setState(117);
      funcbody();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(119);
      match(KafeParser::T__12);
      setState(120);
      match(KafeParser::NAME);
      setState(122);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == KafeParser::T__27) {
        setState(121);
        argslist();
      }
      setState(124);
      structbody();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(125);
      getstructmember();
      break;
    }

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


KafeParser::RetstatContext* KafeParser::retstat() {
  RetstatContext *_localctx = _tracker.createInstance<RetstatContext>(_ctx, getState());
  enterRule(_localctx, 6, KafeParser::RuleRetstat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(128);
    match(KafeParser::T__13);
    setState(129);
    exp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarqualifierContext ------------------------------------------------------------------

KafeParser::VarqualifierContext::VarqualifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t KafeParser::VarqualifierContext::getRuleIndex() const {
  return KafeParser::RuleVarqualifier;
}


KafeParser::VarqualifierContext* KafeParser::varqualifier() {
  VarqualifierContext *_localctx = _tracker.createInstance<VarqualifierContext>(_ctx, getState());
  enterRule(_localctx, 8, KafeParser::RuleVarqualifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(131);
    _la = _input->LA(1);
    if (!(_la == KafeParser::T__14

    || _la == KafeParser::T__15)) {
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


KafeParser::TypeContext* KafeParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 10, KafeParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(140);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case KafeParser::T__16: {
        enterOuterAlt(_localctx, 1);
        setState(133);
        match(KafeParser::T__16);
        break;
      }

      case KafeParser::T__17: {
        enterOuterAlt(_localctx, 2);
        setState(134);
        match(KafeParser::T__17);
        break;
      }

      case KafeParser::T__18: {
        enterOuterAlt(_localctx, 3);
        setState(135);
        match(KafeParser::T__18);
        break;
      }

      case KafeParser::T__19: {
        enterOuterAlt(_localctx, 4);
        setState(136);
        match(KafeParser::T__19);
        break;
      }

      case KafeParser::T__20: {
        enterOuterAlt(_localctx, 5);
        setState(137);
        match(KafeParser::T__20);
        break;
      }

      case KafeParser::T__12: {
        enterOuterAlt(_localctx, 6);
        setState(138);
        match(KafeParser::T__12);
        setState(139);
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


KafeParser::ExplistContext* KafeParser::explist() {
  ExplistContext *_localctx = _tracker.createInstance<ExplistContext>(_ctx, getState());
  enterRule(_localctx, 12, KafeParser::RuleExplist);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(142);
    exp(0);
    setState(146);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(143);
        exp(0); 
      }
      setState(148);
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

//----------------- GetstructmemberContext ------------------------------------------------------------------

KafeParser::GetstructmemberContext::GetstructmemberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> KafeParser::GetstructmemberContext::NAME() {
  return getTokens(KafeParser::NAME);
}

tree::TerminalNode* KafeParser::GetstructmemberContext::NAME(size_t i) {
  return getToken(KafeParser::NAME, i);
}

KafeParser::GetstructmemberContext* KafeParser::GetstructmemberContext::getstructmember() {
  return getRuleContext<KafeParser::GetstructmemberContext>(0);
}


size_t KafeParser::GetstructmemberContext::getRuleIndex() const {
  return KafeParser::RuleGetstructmember;
}


KafeParser::GetstructmemberContext* KafeParser::getstructmember() {
  GetstructmemberContext *_localctx = _tracker.createInstance<GetstructmemberContext>(_ctx, getState());
  enterRule(_localctx, 14, KafeParser::RuleGetstructmember);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    match(KafeParser::NAME);
    setState(150);
    match(KafeParser::T__21);
    setState(153);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      setState(151);
      match(KafeParser::NAME);
      break;
    }

    case 2: {
      setState(152);
      getstructmember();
      break;
    }

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

KafeParser::GetstructmemberContext* KafeParser::FunctioncallContext::getstructmember() {
  return getRuleContext<KafeParser::GetstructmemberContext>(0);
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


KafeParser::FunctioncallContext* KafeParser::functioncall() {
  FunctioncallContext *_localctx = _tracker.createInstance<FunctioncallContext>(_ctx, getState());
  enterRule(_localctx, 16, KafeParser::RuleFunctioncall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(155);
      match(KafeParser::NAME);
      break;
    }

    case 2: {
      setState(156);
      getstructmember();
      break;
    }

    }
    setState(159);
    match(KafeParser::T__22);
    setState(163);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 25) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 25)) & ((1ULL << (KafeParser::T__24 - 25))
      | (1ULL << (KafeParser::T__25 - 25))
      | (1ULL << (KafeParser::T__26 - 25))
      | (1ULL << (KafeParser::T__39 - 25))
      | (1ULL << (KafeParser::T__46 - 25))
      | (1ULL << (KafeParser::T__50 - 25))
      | (1ULL << (KafeParser::T__64 - 25))
      | (1ULL << (KafeParser::NAME - 25))
      | (1ULL << (KafeParser::NORMALSTRING - 25))
      | (1ULL << (KafeParser::CHARSTRING - 25))
      | (1ULL << (KafeParser::INT - 25))
      | (1ULL << (KafeParser::HEX - 25))
      | (1ULL << (KafeParser::FLOAT - 25))
      | (1ULL << (KafeParser::HEX_FLOAT - 25)))) != 0)) {
      setState(160);
      explist();
      setState(165);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(166);
    match(KafeParser::T__23);
   
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

tree::TerminalNode* KafeParser::ExpContext::NAME() {
  return getToken(KafeParser::NAME, 0);
}

KafeParser::FunctioncallContext* KafeParser::ExpContext::functioncall() {
  return getRuleContext<KafeParser::FunctioncallContext>(0);
}

KafeParser::GetstructmemberContext* KafeParser::ExpContext::getstructmember() {
  return getRuleContext<KafeParser::GetstructmemberContext>(0);
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



KafeParser::ExpContext* KafeParser::exp() {
   return exp(0);
}

KafeParser::ExpContext* KafeParser::exp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  KafeParser::ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, parentState);
  KafeParser::ExpContext *previousContext = _localctx;
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, KafeParser::RuleExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(181);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(169);
      match(KafeParser::T__24);
      break;
    }

    case 2: {
      setState(170);
      match(KafeParser::T__25);
      break;
    }

    case 3: {
      setState(171);
      match(KafeParser::T__26);
      break;
    }

    case 4: {
      setState(172);
      number();
      break;
    }

    case 5: {
      setState(173);
      string();
      break;
    }

    case 6: {
      setState(174);
      list();
      break;
    }

    case 7: {
      setState(175);
      match(KafeParser::NAME);
      break;
    }

    case 8: {
      setState(176);
      functioncall();
      break;
    }

    case 9: {
      setState(177);
      getstructmember();
      break;
    }

    case 10: {
      setState(178);
      operatorUnary();
      setState(179);
      exp(8);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(217);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(215);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(183);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(184);
          operatorPower();
          setState(185);
          exp(9);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(187);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(188);
          operatorMulDivMod();
          setState(189);
          exp(8);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(191);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(192);
          operatorAddSub();
          setState(193);
          exp(7);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(195);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(196);
          operatorStrcat();
          setState(197);
          exp(5);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(199);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(200);
          operatorComparison();
          setState(201);
          exp(5);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(203);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(204);
          operatorAnd();
          setState(205);
          exp(4);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(207);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(208);
          operatorOr();
          setState(209);
          exp(3);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(211);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(212);
          operatorBitwise();
          setState(213);
          exp(2);
          break;
        }

        } 
      }
      setState(219);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
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


KafeParser::ArgslistContext* KafeParser::argslist() {
  ArgslistContext *_localctx = _tracker.createInstance<ArgslistContext>(_ctx, getState());
  enterRule(_localctx, 20, KafeParser::RuleArgslist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(220);
    match(KafeParser::T__27);
    setState(227); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(221);
              match(KafeParser::NAME);
              setState(222);
              match(KafeParser::T__0);
              setState(223);
              type();
              setState(225);
              _errHandler->sync(this);

              _la = _input->LA(1);
              if (_la == KafeParser::T__28) {
                setState(224);
                match(KafeParser::T__28);
              }
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(229); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
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


KafeParser::FuncbodyContext* KafeParser::funcbody() {
  FuncbodyContext *_localctx = _tracker.createInstance<FuncbodyContext>(_ctx, getState());
  enterRule(_localctx, 22, KafeParser::RuleFuncbody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(231);
    block();
    setState(232);
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


KafeParser::StructbodyContext* KafeParser::structbody() {
  StructbodyContext *_localctx = _tracker.createInstance<StructbodyContext>(_ctx, getState());
  enterRule(_localctx, 24, KafeParser::RuleStructbody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(234);
    block();
    setState(235);
    match(KafeParser::T__5);
   
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


KafeParser::OperatorOrContext* KafeParser::operatorOr() {
  OperatorOrContext *_localctx = _tracker.createInstance<OperatorOrContext>(_ctx, getState());
  enterRule(_localctx, 26, KafeParser::RuleOperatorOr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(237);
    match(KafeParser::T__29);
   
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


KafeParser::OperatorAndContext* KafeParser::operatorAnd() {
  OperatorAndContext *_localctx = _tracker.createInstance<OperatorAndContext>(_ctx, getState());
  enterRule(_localctx, 28, KafeParser::RuleOperatorAnd);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(239);
    match(KafeParser::T__30);
   
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


KafeParser::OperatorComparisonContext* KafeParser::operatorComparison() {
  OperatorComparisonContext *_localctx = _tracker.createInstance<OperatorComparisonContext>(_ctx, getState());
  enterRule(_localctx, 30, KafeParser::RuleOperatorComparison);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(241);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << KafeParser::T__31)
      | (1ULL << KafeParser::T__32)
      | (1ULL << KafeParser::T__33)
      | (1ULL << KafeParser::T__34)
      | (1ULL << KafeParser::T__35)
      | (1ULL << KafeParser::T__36))) != 0))) {
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


KafeParser::OperatorStrcatContext* KafeParser::operatorStrcat() {
  OperatorStrcatContext *_localctx = _tracker.createInstance<OperatorStrcatContext>(_ctx, getState());
  enterRule(_localctx, 32, KafeParser::RuleOperatorStrcat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(243);
    match(KafeParser::T__37);
   
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


KafeParser::OperatorAddSubContext* KafeParser::operatorAddSub() {
  OperatorAddSubContext *_localctx = _tracker.createInstance<OperatorAddSubContext>(_ctx, getState());
  enterRule(_localctx, 34, KafeParser::RuleOperatorAddSub);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(245);
    _la = _input->LA(1);
    if (!(_la == KafeParser::T__38

    || _la == KafeParser::T__39)) {
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


KafeParser::OperatorMulDivModContext* KafeParser::operatorMulDivMod() {
  OperatorMulDivModContext *_localctx = _tracker.createInstance<OperatorMulDivModContext>(_ctx, getState());
  enterRule(_localctx, 36, KafeParser::RuleOperatorMulDivMod);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(247);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << KafeParser::T__40)
      | (1ULL << KafeParser::T__41)
      | (1ULL << KafeParser::T__42)
      | (1ULL << KafeParser::T__43))) != 0))) {
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


KafeParser::OperatorBitwiseContext* KafeParser::operatorBitwise() {
  OperatorBitwiseContext *_localctx = _tracker.createInstance<OperatorBitwiseContext>(_ctx, getState());
  enterRule(_localctx, 38, KafeParser::RuleOperatorBitwise);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << KafeParser::T__44)
      | (1ULL << KafeParser::T__45)
      | (1ULL << KafeParser::T__46)
      | (1ULL << KafeParser::T__47)
      | (1ULL << KafeParser::T__48)
      | (1ULL << KafeParser::T__49))) != 0))) {
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


KafeParser::OperatorUnaryContext* KafeParser::operatorUnary() {
  OperatorUnaryContext *_localctx = _tracker.createInstance<OperatorUnaryContext>(_ctx, getState());
  enterRule(_localctx, 40, KafeParser::RuleOperatorUnary);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(251);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << KafeParser::T__39)
      | (1ULL << KafeParser::T__46)
      | (1ULL << KafeParser::T__50))) != 0))) {
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


KafeParser::OperatorPowerContext* KafeParser::operatorPower() {
  OperatorPowerContext *_localctx = _tracker.createInstance<OperatorPowerContext>(_ctx, getState());
  enterRule(_localctx, 42, KafeParser::RuleOperatorPower);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(253);
    match(KafeParser::T__51);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperatorMathAffectationContext ------------------------------------------------------------------

KafeParser::OperatorMathAffectationContext::OperatorMathAffectationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t KafeParser::OperatorMathAffectationContext::getRuleIndex() const {
  return KafeParser::RuleOperatorMathAffectation;
}


KafeParser::OperatorMathAffectationContext* KafeParser::operatorMathAffectation() {
  OperatorMathAffectationContext *_localctx = _tracker.createInstance<OperatorMathAffectationContext>(_ctx, getState());
  enterRule(_localctx, 44, KafeParser::RuleOperatorMathAffectation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(255);
    _la = _input->LA(1);
    if (!(((((_la - 53) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 53)) & ((1ULL << (KafeParser::T__52 - 53))
      | (1ULL << (KafeParser::T__53 - 53))
      | (1ULL << (KafeParser::T__54 - 53))
      | (1ULL << (KafeParser::T__55 - 53))
      | (1ULL << (KafeParser::T__56 - 53))
      | (1ULL << (KafeParser::T__57 - 53))
      | (1ULL << (KafeParser::T__58 - 53))
      | (1ULL << (KafeParser::T__59 - 53))
      | (1ULL << (KafeParser::T__60 - 53))
      | (1ULL << (KafeParser::T__61 - 53))
      | (1ULL << (KafeParser::T__62 - 53))
      | (1ULL << (KafeParser::T__63 - 53)))) != 0))) {
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


KafeParser::NumberContext* KafeParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 46, KafeParser::RuleNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(257);
    _la = _input->LA(1);
    if (!(((((_la - 70) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 70)) & ((1ULL << (KafeParser::INT - 70))
      | (1ULL << (KafeParser::HEX - 70))
      | (1ULL << (KafeParser::FLOAT - 70))
      | (1ULL << (KafeParser::HEX_FLOAT - 70)))) != 0))) {
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


KafeParser::StringContext* KafeParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 48, KafeParser::RuleString);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(259);
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


KafeParser::ListContext* KafeParser::list() {
  ListContext *_localctx = _tracker.createInstance<ListContext>(_ctx, getState());
  enterRule(_localctx, 50, KafeParser::RuleList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(261);
    match(KafeParser::T__64);
    setState(262);
    explist();
    setState(263);
    match(KafeParser::T__65);
   
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
    case 9: return expSempred(dynamic_cast<ExpContext *>(context), predicateIndex);

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
  "chunk", "block", "stat", "retstat", "varqualifier", "type", "explist", 
  "getstructmember", "functioncall", "exp", "argslist", "funcbody", "structbody", 
  "operatorOr", "operatorAnd", "operatorComparison", "operatorStrcat", "operatorAddSub", 
  "operatorMulDivMod", "operatorBitwise", "operatorUnary", "operatorPower", 
  "operatorMathAffectation", "number", "string", "list"
};

std::vector<std::string> KafeParser::_literalNames = {
  "", "':'", "'='", "'for'", "'in'", "'do'", "'end'", "'if'", "'then'", 
  "'elif'", "'else'", "'while'", "'fun'", "'struct'", "'ret'", "'dyn'", 
  "'cst'", "'string'", "'int'", "'double'", "'list'", "'bool'", "'.'", "'('", 
  "')'", "'nil'", "'false'", "'true'", "'--'", "','", "'or'", "'and'", "'<'", 
  "'>'", "'<='", "'>='", "'!='", "'=='", "'..'", "'+'", "'-'", "'*'", "'/'", 
  "'%'", "'//'", "'&'", "'|'", "'~'", "'<<'", "'>>'", "'^'", "'not'", "'**'", 
  "'+='", "'-='", "'*='", "'/='", "'%='", "'**='", "'..='", "'&='", "'|='", 
  "'<<='", "'>>='", "'^='", "'['", "']'"
};

std::vector<std::string> KafeParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "NAME", "NORMALSTRING", 
  "CHARSTRING", "INT", "HEX", "FLOAT", "HEX_FLOAT", "COMMENT", "WS"
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
    0x3, 0x4d, 0x10c, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x7, 0x3, 0x3b, 0xa, 0x3, 0xc, 
    0x3, 0xe, 0x3, 0x3e, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x7, 0x4, 0x60, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x63, 0xb, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x5, 0x4, 0x67, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x76, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x7d, 0xa, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x5, 0x4, 0x81, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x5, 0x7, 0x8f, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x93, 
    0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x96, 0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x5, 0x9, 0x9c, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 
    0xa0, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xa4, 0xa, 0xa, 0xc, 0xa, 
    0xe, 0xa, 0xa7, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xb8, 0xa, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xda, 0xa, 0xb, 0xc, 0xb, 0xe, 
    0xb, 0xdd, 0xb, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x5, 0xc, 0xe4, 0xa, 0xc, 0x6, 0xc, 0xe6, 0xa, 0xc, 0xd, 0xc, 0xe, 0xc, 
    0xe7, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
    0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x2, 0x3, 0x14, 0x1c, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 
    0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x2, 0xb, 
    0x3, 0x2, 0x11, 0x12, 0x3, 0x2, 0x22, 0x27, 0x3, 0x2, 0x29, 0x2a, 0x3, 
    0x2, 0x2b, 0x2e, 0x3, 0x2, 0x2f, 0x34, 0x5, 0x2, 0x2a, 0x2a, 0x31, 0x31, 
    0x35, 0x35, 0x3, 0x2, 0x37, 0x42, 0x3, 0x2, 0x48, 0x4b, 0x3, 0x2, 0x46, 
    0x47, 0x2, 0x11b, 0x2, 0x36, 0x3, 0x2, 0x2, 0x2, 0x4, 0x3c, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x80, 0x3, 0x2, 0x2, 0x2, 0x8, 0x82, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x85, 0x3, 0x2, 0x2, 0x2, 0xc, 0x8e, 0x3, 0x2, 0x2, 0x2, 0xe, 0x90, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x97, 0x3, 0x2, 0x2, 0x2, 0x12, 0x9f, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x16, 0xde, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0xe9, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xec, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0xef, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xf1, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0xf3, 0x3, 0x2, 0x2, 0x2, 0x22, 0xf5, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0xf7, 0x3, 0x2, 0x2, 0x2, 0x26, 0xf9, 0x3, 0x2, 0x2, 0x2, 0x28, 0xfb, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xff, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x101, 0x3, 0x2, 0x2, 0x2, 0x30, 0x103, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x105, 0x3, 0x2, 0x2, 0x2, 0x34, 0x107, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x37, 0x5, 0x4, 0x3, 0x2, 0x37, 0x38, 0x7, 0x2, 0x2, 0x3, 
    0x38, 0x3, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3b, 0x5, 0x6, 0x4, 0x2, 0x3a, 
    0x39, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3a, 
    0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x3e, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x5, 0xa, 
    0x6, 0x2, 0x40, 0x41, 0x7, 0x45, 0x2, 0x2, 0x41, 0x42, 0x7, 0x3, 0x2, 
    0x2, 0x42, 0x43, 0x5, 0xc, 0x7, 0x2, 0x43, 0x44, 0x7, 0x4, 0x2, 0x2, 
    0x44, 0x45, 0x5, 0xe, 0x8, 0x2, 0x45, 0x81, 0x3, 0x2, 0x2, 0x2, 0x46, 
    0x47, 0x7, 0x45, 0x2, 0x2, 0x47, 0x48, 0x7, 0x4, 0x2, 0x2, 0x48, 0x81, 
    0x5, 0xe, 0x8, 0x2, 0x49, 0x4a, 0x7, 0x45, 0x2, 0x2, 0x4a, 0x4b, 0x5, 
    0x2e, 0x18, 0x2, 0x4b, 0x4c, 0x5, 0xe, 0x8, 0x2, 0x4c, 0x81, 0x3, 0x2, 
    0x2, 0x2, 0x4d, 0x81, 0x5, 0x12, 0xa, 0x2, 0x4e, 0x4f, 0x7, 0x5, 0x2, 
    0x2, 0x4f, 0x50, 0x7, 0x45, 0x2, 0x2, 0x50, 0x51, 0x7, 0x6, 0x2, 0x2, 
    0x51, 0x52, 0x5, 0x14, 0xb, 0x2, 0x52, 0x53, 0x7, 0x7, 0x2, 0x2, 0x53, 
    0x54, 0x5, 0x4, 0x3, 0x2, 0x54, 0x55, 0x7, 0x8, 0x2, 0x2, 0x55, 0x81, 
    0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0x7, 0x9, 0x2, 0x2, 0x57, 0x58, 0x5, 
    0x14, 0xb, 0x2, 0x58, 0x59, 0x7, 0xa, 0x2, 0x2, 0x59, 0x61, 0x5, 0x4, 
    0x3, 0x2, 0x5a, 0x5b, 0x7, 0xb, 0x2, 0x2, 0x5b, 0x5c, 0x5, 0x14, 0xb, 
    0x2, 0x5c, 0x5d, 0x7, 0xa, 0x2, 0x2, 0x5d, 0x5e, 0x5, 0x4, 0x3, 0x2, 
    0x5e, 0x60, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x60, 
    0x63, 0x3, 0x2, 0x2, 0x2, 0x61, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 
    0x3, 0x2, 0x2, 0x2, 0x62, 0x66, 0x3, 0x2, 0x2, 0x2, 0x63, 0x61, 0x3, 
    0x2, 0x2, 0x2, 0x64, 0x65, 0x7, 0xc, 0x2, 0x2, 0x65, 0x67, 0x5, 0x4, 
    0x3, 0x2, 0x66, 0x64, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 0x3, 0x2, 0x2, 
    0x2, 0x67, 0x68, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x7, 0x8, 0x2, 0x2, 
    0x69, 0x81, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x7, 0xd, 0x2, 0x2, 0x6b, 
    0x6c, 0x5, 0x14, 0xb, 0x2, 0x6c, 0x6d, 0x7, 0x7, 0x2, 0x2, 0x6d, 0x6e, 
    0x5, 0x4, 0x3, 0x2, 0x6e, 0x6f, 0x7, 0x8, 0x2, 0x2, 0x6f, 0x81, 0x3, 
    0x2, 0x2, 0x2, 0x70, 0x71, 0x7, 0xe, 0x2, 0x2, 0x71, 0x72, 0x7, 0x45, 
    0x2, 0x2, 0x72, 0x73, 0x7, 0x3, 0x2, 0x2, 0x73, 0x75, 0x5, 0xc, 0x7, 
    0x2, 0x74, 0x76, 0x5, 0x16, 0xc, 0x2, 0x75, 0x74, 0x3, 0x2, 0x2, 0x2, 
    0x75, 0x76, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x3, 0x2, 0x2, 0x2, 0x77, 
    0x78, 0x5, 0x18, 0xd, 0x2, 0x78, 0x81, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 
    0x7, 0xf, 0x2, 0x2, 0x7a, 0x7c, 0x7, 0x45, 0x2, 0x2, 0x7b, 0x7d, 0x5, 
    0x16, 0xc, 0x2, 0x7c, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x3, 0x2, 
    0x2, 0x2, 0x7d, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x81, 0x5, 0x1a, 0xe, 
    0x2, 0x7f, 0x81, 0x5, 0x10, 0x9, 0x2, 0x80, 0x3f, 0x3, 0x2, 0x2, 0x2, 
    0x80, 0x46, 0x3, 0x2, 0x2, 0x2, 0x80, 0x49, 0x3, 0x2, 0x2, 0x2, 0x80, 
    0x4d, 0x3, 0x2, 0x2, 0x2, 0x80, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x80, 0x56, 
    0x3, 0x2, 0x2, 0x2, 0x80, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x80, 0x70, 0x3, 
    0x2, 0x2, 0x2, 0x80, 0x79, 0x3, 0x2, 0x2, 0x2, 0x80, 0x7f, 0x3, 0x2, 
    0x2, 0x2, 0x81, 0x7, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x7, 0x10, 0x2, 
    0x2, 0x83, 0x84, 0x5, 0x14, 0xb, 0x2, 0x84, 0x9, 0x3, 0x2, 0x2, 0x2, 
    0x85, 0x86, 0x9, 0x2, 0x2, 0x2, 0x86, 0xb, 0x3, 0x2, 0x2, 0x2, 0x87, 
    0x8f, 0x7, 0x13, 0x2, 0x2, 0x88, 0x8f, 0x7, 0x14, 0x2, 0x2, 0x89, 0x8f, 
    0x7, 0x15, 0x2, 0x2, 0x8a, 0x8f, 0x7, 0x16, 0x2, 0x2, 0x8b, 0x8f, 0x7, 
    0x17, 0x2, 0x2, 0x8c, 0x8d, 0x7, 0xf, 0x2, 0x2, 0x8d, 0x8f, 0x7, 0x45, 
    0x2, 0x2, 0x8e, 0x87, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x88, 0x3, 0x2, 0x2, 
    0x2, 0x8e, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8a, 0x3, 0x2, 0x2, 0x2, 
    0x8e, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8f, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0x90, 0x94, 0x5, 0x14, 0xb, 0x2, 0x91, 0x93, 
    0x5, 0x14, 0xb, 0x2, 0x92, 0x91, 0x3, 0x2, 0x2, 0x2, 0x93, 0x96, 0x3, 
    0x2, 0x2, 0x2, 0x94, 0x92, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x3, 0x2, 
    0x2, 0x2, 0x95, 0xf, 0x3, 0x2, 0x2, 0x2, 0x96, 0x94, 0x3, 0x2, 0x2, 
    0x2, 0x97, 0x98, 0x7, 0x45, 0x2, 0x2, 0x98, 0x9b, 0x7, 0x18, 0x2, 0x2, 
    0x99, 0x9c, 0x7, 0x45, 0x2, 0x2, 0x9a, 0x9c, 0x5, 0x10, 0x9, 0x2, 0x9b, 
    0x99, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0x9d, 0xa0, 0x7, 0x45, 0x2, 0x2, 0x9e, 0xa0, 0x5, 
    0x10, 0x9, 0x2, 0x9f, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x9e, 0x3, 0x2, 
    0x2, 0x2, 0xa0, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa5, 0x7, 0x19, 0x2, 
    0x2, 0xa2, 0xa4, 0x5, 0xe, 0x8, 0x2, 0xa3, 0xa2, 0x3, 0x2, 0x2, 0x2, 
    0xa4, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa5, 
    0xa6, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa5, 
    0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x7, 0x1a, 0x2, 0x2, 0xa9, 0x13, 0x3, 
    0x2, 0x2, 0x2, 0xaa, 0xab, 0x8, 0xb, 0x1, 0x2, 0xab, 0xb8, 0x7, 0x1b, 
    0x2, 0x2, 0xac, 0xb8, 0x7, 0x1c, 0x2, 0x2, 0xad, 0xb8, 0x7, 0x1d, 0x2, 
    0x2, 0xae, 0xb8, 0x5, 0x30, 0x19, 0x2, 0xaf, 0xb8, 0x5, 0x32, 0x1a, 
    0x2, 0xb0, 0xb8, 0x5, 0x34, 0x1b, 0x2, 0xb1, 0xb8, 0x7, 0x45, 0x2, 0x2, 
    0xb2, 0xb8, 0x5, 0x12, 0xa, 0x2, 0xb3, 0xb8, 0x5, 0x10, 0x9, 0x2, 0xb4, 
    0xb5, 0x5, 0x2a, 0x16, 0x2, 0xb5, 0xb6, 0x5, 0x14, 0xb, 0xa, 0xb6, 0xb8, 
    0x3, 0x2, 0x2, 0x2, 0xb7, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xac, 0x3, 
    0x2, 0x2, 0x2, 0xb7, 0xad, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xae, 0x3, 0x2, 
    0x2, 0x2, 0xb7, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb0, 0x3, 0x2, 0x2, 
    0x2, 0xb7, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb2, 0x3, 0x2, 0x2, 0x2, 
    0xb7, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb8, 
    0xdb, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0xc, 0xb, 0x2, 0x2, 0xba, 0xbb, 
    0x5, 0x2c, 0x17, 0x2, 0xbb, 0xbc, 0x5, 0x14, 0xb, 0xb, 0xbc, 0xda, 0x3, 
    0x2, 0x2, 0x2, 0xbd, 0xbe, 0xc, 0x9, 0x2, 0x2, 0xbe, 0xbf, 0x5, 0x26, 
    0x14, 0x2, 0xbf, 0xc0, 0x5, 0x14, 0xb, 0xa, 0xc0, 0xda, 0x3, 0x2, 0x2, 
    0x2, 0xc1, 0xc2, 0xc, 0x8, 0x2, 0x2, 0xc2, 0xc3, 0x5, 0x24, 0x13, 0x2, 
    0xc3, 0xc4, 0x5, 0x14, 0xb, 0x9, 0xc4, 0xda, 0x3, 0x2, 0x2, 0x2, 0xc5, 
    0xc6, 0xc, 0x7, 0x2, 0x2, 0xc6, 0xc7, 0x5, 0x22, 0x12, 0x2, 0xc7, 0xc8, 
    0x5, 0x14, 0xb, 0x7, 0xc8, 0xda, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0xc, 
    0x6, 0x2, 0x2, 0xca, 0xcb, 0x5, 0x20, 0x11, 0x2, 0xcb, 0xcc, 0x5, 0x14, 
    0xb, 0x7, 0xcc, 0xda, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0xc, 0x5, 0x2, 
    0x2, 0xce, 0xcf, 0x5, 0x1e, 0x10, 0x2, 0xcf, 0xd0, 0x5, 0x14, 0xb, 0x6, 
    0xd0, 0xda, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0xc, 0x4, 0x2, 0x2, 0xd2, 
    0xd3, 0x5, 0x1c, 0xf, 0x2, 0xd3, 0xd4, 0x5, 0x14, 0xb, 0x5, 0xd4, 0xda, 
    0x3, 0x2, 0x2, 0x2, 0xd5, 0xd6, 0xc, 0x3, 0x2, 0x2, 0xd6, 0xd7, 0x5, 
    0x28, 0x15, 0x2, 0xd7, 0xd8, 0x5, 0x14, 0xb, 0x4, 0xd8, 0xda, 0x3, 0x2, 
    0x2, 0x2, 0xd9, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xbd, 0x3, 0x2, 0x2, 
    0x2, 0xd9, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xc5, 0x3, 0x2, 0x2, 0x2, 
    0xd9, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xd9, 
    0xd1, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdd, 
    0x3, 0x2, 0x2, 0x2, 0xdb, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x3, 
    0x2, 0x2, 0x2, 0xdc, 0x15, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdb, 0x3, 0x2, 
    0x2, 0x2, 0xde, 0xe5, 0x7, 0x1e, 0x2, 0x2, 0xdf, 0xe0, 0x7, 0x45, 0x2, 
    0x2, 0xe0, 0xe1, 0x7, 0x3, 0x2, 0x2, 0xe1, 0xe3, 0x5, 0xc, 0x7, 0x2, 
    0xe2, 0xe4, 0x7, 0x1f, 0x2, 0x2, 0xe3, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe3, 
    0xe4, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xdf, 
    0x3, 0x2, 0x2, 0x2, 0xe6, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe5, 0x3, 
    0x2, 0x2, 0x2, 0xe7, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xe8, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0xe9, 0xea, 0x5, 0x4, 0x3, 0x2, 0xea, 0xeb, 0x5, 0x8, 0x5, 
    0x2, 0xeb, 0x19, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x5, 0x4, 0x3, 0x2, 
    0xed, 0xee, 0x7, 0x8, 0x2, 0x2, 0xee, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xef, 
    0xf0, 0x7, 0x20, 0x2, 0x2, 0xf0, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 
    0x7, 0x21, 0x2, 0x2, 0xf2, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x9, 
    0x3, 0x2, 0x2, 0xf4, 0x21, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 0x7, 0x28, 
    0x2, 0x2, 0xf6, 0x23, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 0x9, 0x4, 0x2, 
    0x2, 0xf8, 0x25, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x9, 0x5, 0x2, 0x2, 
    0xfa, 0x27, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x9, 0x6, 0x2, 0x2, 0xfc, 
    0x29, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfe, 0x9, 0x7, 0x2, 0x2, 0xfe, 0x2b, 
    0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 0x7, 0x36, 0x2, 0x2, 0x100, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0x101, 0x102, 0x9, 0x8, 0x2, 0x2, 0x102, 0x2f, 0x3, 0x2, 
    0x2, 0x2, 0x103, 0x104, 0x9, 0x9, 0x2, 0x2, 0x104, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x105, 0x106, 0x9, 0xa, 0x2, 0x2, 0x106, 0x33, 0x3, 0x2, 0x2, 0x2, 
    0x107, 0x108, 0x7, 0x43, 0x2, 0x2, 0x108, 0x109, 0x5, 0xe, 0x8, 0x2, 
    0x109, 0x10a, 0x7, 0x44, 0x2, 0x2, 0x10a, 0x35, 0x3, 0x2, 0x2, 0x2, 
    0x12, 0x3c, 0x61, 0x66, 0x75, 0x7c, 0x80, 0x8e, 0x94, 0x9b, 0x9f, 0xa5, 
    0xb7, 0xd9, 0xdb, 0xe3, 0xe7, 
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
