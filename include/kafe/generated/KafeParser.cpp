
#ifdef _MSC_VER
    // if compiling with visual studio, disable those warnings
    #pragma warning (disable: 4251)  // need a dll to run
    #pragma warning (disable: 4996)  // warnings from codecvt
#endif


// Generated from grammar/Kafe.g4 by ANTLR 4.7.1


#include "KafeVisitor.h"

#include "KafeParser.h"


using namespace antlrcpp;
using namespace antlr4;

KafeParser::KafeParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

KafeParser::~KafeParser() {
  delete _interpreter;
}

std::string KafeParser::getGrammarFileName() const {
  return "Kafe.g4";
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
    setState(56);
    block();
    setState(57);
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
    setState(62);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 5) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 5)) & ((1ULL << (KafeParser::T__4 - 5))
      | (1ULL << (KafeParser::T__5 - 5))
      | (1ULL << (KafeParser::T__9 - 5))
      | (1ULL << (KafeParser::T__13 - 5))
      | (1ULL << (KafeParser::T__14 - 5))
      | (1ULL << (KafeParser::T__16 - 5))
      | (1ULL << (KafeParser::T__18 - 5))
      | (1ULL << (KafeParser::T__19 - 5))
      | (1ULL << (KafeParser::NAME - 5)))) != 0)) {
      setState(59);
      stat();
      setState(64);
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

std::vector<tree::TerminalNode *> KafeParser::StatContext::NAME() {
  return getTokens(KafeParser::NAME);
}

tree::TerminalNode* KafeParser::StatContext::NAME(size_t i) {
  return getToken(KafeParser::NAME, i);
}

std::vector<KafeParser::ExplistContext *> KafeParser::StatContext::explist() {
  return getRuleContexts<KafeParser::ExplistContext>();
}

KafeParser::ExplistContext* KafeParser::StatContext::explist(size_t i) {
  return getRuleContext<KafeParser::ExplistContext>(i);
}

KafeParser::NamelistContext* KafeParser::StatContext::namelist() {
  return getRuleContext<KafeParser::NamelistContext>(0);
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

KafeParser::ArgslistContext* KafeParser::StatContext::argslist() {
  return getRuleContext<KafeParser::ArgslistContext>(0);
}

KafeParser::TypeContext* KafeParser::StatContext::type() {
  return getRuleContext<KafeParser::TypeContext>(0);
}

KafeParser::FuncbodyContext* KafeParser::StatContext::funcbody() {
  return getRuleContext<KafeParser::FuncbodyContext>(0);
}

KafeParser::StructbodyContext* KafeParser::StatContext::structbody() {
  return getRuleContext<KafeParser::StructbodyContext>(0);
}

KafeParser::StructparentsContext* KafeParser::StatContext::structparents() {
  return getRuleContext<KafeParser::StructparentsContext>(0);
}

KafeParser::GetstructmemberContext* KafeParser::StatContext::getstructmember() {
  return getRuleContext<KafeParser::GetstructmemberContext>(0);
}


size_t KafeParser::StatContext::getRuleIndex() const {
  return KafeParser::RuleStat;
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
    setState(142);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(65);
      varqualifier();
      setState(66);
      match(KafeParser::NAME);
      setState(67);
      match(KafeParser::T__0);
      setState(68);
      explist();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(70);
      varqualifier();
      setState(71);
      match(KafeParser::NAME);
      setState(72);
      match(KafeParser::T__1);
      setState(73);
      match(KafeParser::NAME);
      setState(74);
      match(KafeParser::T__2);
      setState(78);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (((((_la - 28) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 28)) & ((1ULL << (KafeParser::T__27 - 28))
        | (1ULL << (KafeParser::T__28 - 28))
        | (1ULL << (KafeParser::T__29 - 28))
        | (1ULL << (KafeParser::T__40 - 28))
        | (1ULL << (KafeParser::T__47 - 28))
        | (1ULL << (KafeParser::T__51 - 28))
        | (1ULL << (KafeParser::T__65 - 28))
        | (1ULL << (KafeParser::NAME - 28))
        | (1ULL << (KafeParser::NORMALSTRING - 28))
        | (1ULL << (KafeParser::CHARSTRING - 28))
        | (1ULL << (KafeParser::INT - 28))
        | (1ULL << (KafeParser::HEX - 28))
        | (1ULL << (KafeParser::FLOAT - 28))
        | (1ULL << (KafeParser::HEX_FLOAT - 28)))) != 0)) {
        setState(75);
        explist();
        setState(80);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(81);
      match(KafeParser::T__3);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(83);
      match(KafeParser::T__4);
      setState(84);
      namelist();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(85);
      match(KafeParser::NAME);
      setState(86);
      match(KafeParser::T__0);
      setState(87);
      explist();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(88);
      match(KafeParser::NAME);
      setState(89);
      operatorMathAffectation();
      setState(90);
      explist();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(92);
      functioncall();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(93);
      match(KafeParser::T__5);
      setState(94);
      match(KafeParser::NAME);
      setState(95);
      match(KafeParser::T__6);
      setState(96);
      exp(0);
      setState(97);
      match(KafeParser::T__7);
      setState(98);
      block();
      setState(99);
      match(KafeParser::T__8);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(101);
      match(KafeParser::T__9);
      setState(102);
      exp(0);
      setState(103);
      match(KafeParser::T__10);
      setState(104);
      block();
      setState(112);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == KafeParser::T__11) {
        setState(105);
        match(KafeParser::T__11);
        setState(106);
        exp(0);
        setState(107);
        match(KafeParser::T__10);
        setState(108);
        block();
        setState(114);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(117);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == KafeParser::T__12) {
        setState(115);
        match(KafeParser::T__12);
        setState(116);
        block();
      }
      setState(119);
      match(KafeParser::T__8);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(121);
      match(KafeParser::T__13);
      setState(122);
      exp(0);
      setState(123);
      match(KafeParser::T__7);
      setState(124);
      block();
      setState(125);
      match(KafeParser::T__8);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(127);
      match(KafeParser::T__14);
      setState(128);
      match(KafeParser::NAME);
      setState(129);
      argslist();
      setState(130);
      match(KafeParser::T__15);
      setState(131);
      type();
      setState(132);
      funcbody();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(134);
      match(KafeParser::T__16);
      setState(135);
      match(KafeParser::NAME);
      setState(138);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == KafeParser::T__1) {
        setState(136);
        match(KafeParser::T__1);
        setState(137);
        structparents();
      }
      setState(140);
      structbody();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(141);
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
    setState(144);
    match(KafeParser::T__17);
    setState(145);
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

antlrcpp::Any KafeParser::VarqualifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitVarqualifier(this);
  else
    return visitor->visitChildren(this);
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
    setState(147);
    _la = _input->LA(1);
    if (!(_la == KafeParser::T__18

    || _la == KafeParser::T__19)) {
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

antlrcpp::Any KafeParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::TypeContext* KafeParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 10, KafeParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(156);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case KafeParser::T__20: {
        enterOuterAlt(_localctx, 1);
        setState(149);
        match(KafeParser::T__20);
        break;
      }

      case KafeParser::T__21: {
        enterOuterAlt(_localctx, 2);
        setState(150);
        match(KafeParser::T__21);
        break;
      }

      case KafeParser::T__22: {
        enterOuterAlt(_localctx, 3);
        setState(151);
        match(KafeParser::T__22);
        break;
      }

      case KafeParser::T__23: {
        enterOuterAlt(_localctx, 4);
        setState(152);
        match(KafeParser::T__23);
        break;
      }

      case KafeParser::T__24: {
        enterOuterAlt(_localctx, 5);
        setState(153);
        match(KafeParser::T__24);
        break;
      }

      case KafeParser::T__16: {
        enterOuterAlt(_localctx, 6);
        setState(154);
        match(KafeParser::T__16);
        setState(155);
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

//----------------- NamelistContext ------------------------------------------------------------------

KafeParser::NamelistContext::NamelistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> KafeParser::NamelistContext::NAME() {
  return getTokens(KafeParser::NAME);
}

tree::TerminalNode* KafeParser::NamelistContext::NAME(size_t i) {
  return getToken(KafeParser::NAME, i);
}


size_t KafeParser::NamelistContext::getRuleIndex() const {
  return KafeParser::RuleNamelist;
}

antlrcpp::Any KafeParser::NamelistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitNamelist(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::NamelistContext* KafeParser::namelist() {
  NamelistContext *_localctx = _tracker.createInstance<NamelistContext>(_ctx, getState());
  enterRule(_localctx, 12, KafeParser::RuleNamelist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(158);
    match(KafeParser::NAME);
    setState(165);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(160);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == KafeParser::T__25) {
          setState(159);
          match(KafeParser::T__25);
        }
        setState(162);
        match(KafeParser::NAME); 
      }
      setState(167);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
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

antlrcpp::Any KafeParser::ExplistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitExplist(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::ExplistContext* KafeParser::explist() {
  ExplistContext *_localctx = _tracker.createInstance<ExplistContext>(_ctx, getState());
  enterRule(_localctx, 14, KafeParser::RuleExplist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(168);
    exp(0);
    setState(175);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(170);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == KafeParser::T__25) {
          setState(169);
          match(KafeParser::T__25);
        }
        setState(172);
        exp(0); 
      }
      setState(177);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
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

antlrcpp::Any KafeParser::GetstructmemberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitGetstructmember(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::GetstructmemberContext* KafeParser::getstructmember() {
  GetstructmemberContext *_localctx = _tracker.createInstance<GetstructmemberContext>(_ctx, getState());
  enterRule(_localctx, 16, KafeParser::RuleGetstructmember);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(178);
    match(KafeParser::NAME);
    setState(179);
    match(KafeParser::T__26);
    setState(182);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(180);
      match(KafeParser::NAME);
      break;
    }

    case 2: {
      setState(181);
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

antlrcpp::Any KafeParser::FunctioncallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitFunctioncall(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::FunctioncallContext* KafeParser::functioncall() {
  FunctioncallContext *_localctx = _tracker.createInstance<FunctioncallContext>(_ctx, getState());
  enterRule(_localctx, 18, KafeParser::RuleFunctioncall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      setState(184);
      match(KafeParser::NAME);
      break;
    }

    case 2: {
      setState(185);
      getstructmember();
      break;
    }

    }
    setState(188);
    match(KafeParser::T__2);
    setState(192);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 28) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 28)) & ((1ULL << (KafeParser::T__27 - 28))
      | (1ULL << (KafeParser::T__28 - 28))
      | (1ULL << (KafeParser::T__29 - 28))
      | (1ULL << (KafeParser::T__40 - 28))
      | (1ULL << (KafeParser::T__47 - 28))
      | (1ULL << (KafeParser::T__51 - 28))
      | (1ULL << (KafeParser::T__65 - 28))
      | (1ULL << (KafeParser::NAME - 28))
      | (1ULL << (KafeParser::NORMALSTRING - 28))
      | (1ULL << (KafeParser::CHARSTRING - 28))
      | (1ULL << (KafeParser::INT - 28))
      | (1ULL << (KafeParser::HEX - 28))
      | (1ULL << (KafeParser::FLOAT - 28))
      | (1ULL << (KafeParser::HEX_FLOAT - 28)))) != 0)) {
      setState(189);
      explist();
      setState(194);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(195);
    match(KafeParser::T__3);
   
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
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, KafeParser::RuleExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(210);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(198);
      match(KafeParser::T__27);
      break;
    }

    case 2: {
      setState(199);
      match(KafeParser::T__28);
      break;
    }

    case 3: {
      setState(200);
      match(KafeParser::T__29);
      break;
    }

    case 4: {
      setState(201);
      number();
      break;
    }

    case 5: {
      setState(202);
      string();
      break;
    }

    case 6: {
      setState(203);
      list();
      break;
    }

    case 7: {
      setState(204);
      match(KafeParser::NAME);
      break;
    }

    case 8: {
      setState(205);
      functioncall();
      break;
    }

    case 9: {
      setState(206);
      getstructmember();
      break;
    }

    case 10: {
      setState(207);
      operatorUnary();
      setState(208);
      exp(8);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(246);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(244);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(212);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(213);
          operatorPower();
          setState(214);
          exp(9);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(216);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(217);
          operatorMulDivMod();
          setState(218);
          exp(8);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(220);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(221);
          operatorAddSub();
          setState(222);
          exp(7);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(224);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(225);
          operatorStrcat();
          setState(226);
          exp(5);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(228);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(229);
          operatorComparison();
          setState(230);
          exp(5);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(232);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(233);
          operatorAnd();
          setState(234);
          exp(4);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(236);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(237);
          operatorOr();
          setState(238);
          exp(3);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(240);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(241);
          operatorBitwise();
          setState(242);
          exp(2);
          break;
        }

        } 
      }
      setState(248);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
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

antlrcpp::Any KafeParser::ArgslistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitArgslist(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::ArgslistContext* KafeParser::argslist() {
  ArgslistContext *_localctx = _tracker.createInstance<ArgslistContext>(_ctx, getState());
  enterRule(_localctx, 22, KafeParser::RuleArgslist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    match(KafeParser::T__2);
    setState(258);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == KafeParser::NAME) {
      setState(250);
      match(KafeParser::NAME);
      setState(251);
      match(KafeParser::T__1);
      setState(252);
      type();
      setState(254);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == KafeParser::T__25) {
        setState(253);
        match(KafeParser::T__25);
      }
      setState(260);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(261);
    match(KafeParser::T__3);
   
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

antlrcpp::Any KafeParser::FuncbodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitFuncbody(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::FuncbodyContext* KafeParser::funcbody() {
  FuncbodyContext *_localctx = _tracker.createInstance<FuncbodyContext>(_ctx, getState());
  enterRule(_localctx, 24, KafeParser::RuleFuncbody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(263);
    block();
    setState(264);
    retstat();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructparentsContext ------------------------------------------------------------------

KafeParser::StructparentsContext::StructparentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> KafeParser::StructparentsContext::NAME() {
  return getTokens(KafeParser::NAME);
}

tree::TerminalNode* KafeParser::StructparentsContext::NAME(size_t i) {
  return getToken(KafeParser::NAME, i);
}


size_t KafeParser::StructparentsContext::getRuleIndex() const {
  return KafeParser::RuleStructparents;
}

antlrcpp::Any KafeParser::StructparentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitStructparents(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::StructparentsContext* KafeParser::structparents() {
  StructparentsContext *_localctx = _tracker.createInstance<StructparentsContext>(_ctx, getState());
  enterRule(_localctx, 26, KafeParser::RuleStructparents);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(266);
    match(KafeParser::NAME);
    setState(273);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(268);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == KafeParser::T__25) {
          setState(267);
          match(KafeParser::T__25);
        }
        setState(270);
        match(KafeParser::NAME); 
      }
      setState(275);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
   
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

antlrcpp::Any KafeParser::StructbodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitStructbody(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::StructbodyContext* KafeParser::structbody() {
  StructbodyContext *_localctx = _tracker.createInstance<StructbodyContext>(_ctx, getState());
  enterRule(_localctx, 28, KafeParser::RuleStructbody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(276);
    block();
    setState(277);
    match(KafeParser::T__8);
   
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

antlrcpp::Any KafeParser::OperatorOrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitOperatorOr(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::OperatorOrContext* KafeParser::operatorOr() {
  OperatorOrContext *_localctx = _tracker.createInstance<OperatorOrContext>(_ctx, getState());
  enterRule(_localctx, 30, KafeParser::RuleOperatorOr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(279);
    match(KafeParser::T__30);
   
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

antlrcpp::Any KafeParser::OperatorAndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitOperatorAnd(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::OperatorAndContext* KafeParser::operatorAnd() {
  OperatorAndContext *_localctx = _tracker.createInstance<OperatorAndContext>(_ctx, getState());
  enterRule(_localctx, 32, KafeParser::RuleOperatorAnd);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(281);
    match(KafeParser::T__31);
   
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

antlrcpp::Any KafeParser::OperatorComparisonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitOperatorComparison(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::OperatorComparisonContext* KafeParser::operatorComparison() {
  OperatorComparisonContext *_localctx = _tracker.createInstance<OperatorComparisonContext>(_ctx, getState());
  enterRule(_localctx, 34, KafeParser::RuleOperatorComparison);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(283);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << KafeParser::T__32)
      | (1ULL << KafeParser::T__33)
      | (1ULL << KafeParser::T__34)
      | (1ULL << KafeParser::T__35)
      | (1ULL << KafeParser::T__36)
      | (1ULL << KafeParser::T__37))) != 0))) {
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

antlrcpp::Any KafeParser::OperatorStrcatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitOperatorStrcat(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::OperatorStrcatContext* KafeParser::operatorStrcat() {
  OperatorStrcatContext *_localctx = _tracker.createInstance<OperatorStrcatContext>(_ctx, getState());
  enterRule(_localctx, 36, KafeParser::RuleOperatorStrcat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(285);
    match(KafeParser::T__38);
   
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

antlrcpp::Any KafeParser::OperatorAddSubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitOperatorAddSub(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::OperatorAddSubContext* KafeParser::operatorAddSub() {
  OperatorAddSubContext *_localctx = _tracker.createInstance<OperatorAddSubContext>(_ctx, getState());
  enterRule(_localctx, 38, KafeParser::RuleOperatorAddSub);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(287);
    _la = _input->LA(1);
    if (!(_la == KafeParser::T__39

    || _la == KafeParser::T__40)) {
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

antlrcpp::Any KafeParser::OperatorMulDivModContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitOperatorMulDivMod(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::OperatorMulDivModContext* KafeParser::operatorMulDivMod() {
  OperatorMulDivModContext *_localctx = _tracker.createInstance<OperatorMulDivModContext>(_ctx, getState());
  enterRule(_localctx, 40, KafeParser::RuleOperatorMulDivMod);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(289);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << KafeParser::T__41)
      | (1ULL << KafeParser::T__42)
      | (1ULL << KafeParser::T__43)
      | (1ULL << KafeParser::T__44))) != 0))) {
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

antlrcpp::Any KafeParser::OperatorBitwiseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitOperatorBitwise(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::OperatorBitwiseContext* KafeParser::operatorBitwise() {
  OperatorBitwiseContext *_localctx = _tracker.createInstance<OperatorBitwiseContext>(_ctx, getState());
  enterRule(_localctx, 42, KafeParser::RuleOperatorBitwise);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(291);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << KafeParser::T__45)
      | (1ULL << KafeParser::T__46)
      | (1ULL << KafeParser::T__47)
      | (1ULL << KafeParser::T__48)
      | (1ULL << KafeParser::T__49)
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

//----------------- OperatorUnaryContext ------------------------------------------------------------------

KafeParser::OperatorUnaryContext::OperatorUnaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t KafeParser::OperatorUnaryContext::getRuleIndex() const {
  return KafeParser::RuleOperatorUnary;
}

antlrcpp::Any KafeParser::OperatorUnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitOperatorUnary(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::OperatorUnaryContext* KafeParser::operatorUnary() {
  OperatorUnaryContext *_localctx = _tracker.createInstance<OperatorUnaryContext>(_ctx, getState());
  enterRule(_localctx, 44, KafeParser::RuleOperatorUnary);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(293);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << KafeParser::T__40)
      | (1ULL << KafeParser::T__47)
      | (1ULL << KafeParser::T__51))) != 0))) {
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

antlrcpp::Any KafeParser::OperatorPowerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitOperatorPower(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::OperatorPowerContext* KafeParser::operatorPower() {
  OperatorPowerContext *_localctx = _tracker.createInstance<OperatorPowerContext>(_ctx, getState());
  enterRule(_localctx, 46, KafeParser::RuleOperatorPower);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(295);
    match(KafeParser::T__52);
   
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

antlrcpp::Any KafeParser::OperatorMathAffectationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitOperatorMathAffectation(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::OperatorMathAffectationContext* KafeParser::operatorMathAffectation() {
  OperatorMathAffectationContext *_localctx = _tracker.createInstance<OperatorMathAffectationContext>(_ctx, getState());
  enterRule(_localctx, 48, KafeParser::RuleOperatorMathAffectation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    _la = _input->LA(1);
    if (!(((((_la - 54) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 54)) & ((1ULL << (KafeParser::T__53 - 54))
      | (1ULL << (KafeParser::T__54 - 54))
      | (1ULL << (KafeParser::T__55 - 54))
      | (1ULL << (KafeParser::T__56 - 54))
      | (1ULL << (KafeParser::T__57 - 54))
      | (1ULL << (KafeParser::T__58 - 54))
      | (1ULL << (KafeParser::T__59 - 54))
      | (1ULL << (KafeParser::T__60 - 54))
      | (1ULL << (KafeParser::T__61 - 54))
      | (1ULL << (KafeParser::T__62 - 54))
      | (1ULL << (KafeParser::T__63 - 54))
      | (1ULL << (KafeParser::T__64 - 54)))) != 0))) {
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

antlrcpp::Any KafeParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::NumberContext* KafeParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 50, KafeParser::RuleNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(299);
    _la = _input->LA(1);
    if (!(((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & ((1ULL << (KafeParser::INT - 71))
      | (1ULL << (KafeParser::HEX - 71))
      | (1ULL << (KafeParser::FLOAT - 71))
      | (1ULL << (KafeParser::HEX_FLOAT - 71)))) != 0))) {
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

antlrcpp::Any KafeParser::StringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::StringContext* KafeParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 52, KafeParser::RuleString);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(301);
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

antlrcpp::Any KafeParser::ListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitList(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::ListContext* KafeParser::list() {
  ListContext *_localctx = _tracker.createInstance<ListContext>(_ctx, getState());
  enterRule(_localctx, 54, KafeParser::RuleList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(303);
    match(KafeParser::T__65);
    setState(304);
    explist();
    setState(305);
    match(KafeParser::T__66);
   
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
    case 10: return expSempred(dynamic_cast<ExpContext *>(context), predicateIndex);

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
  "chunk", "block", "stat", "retstat", "varqualifier", "type", "namelist", 
  "explist", "getstructmember", "functioncall", "exp", "argslist", "funcbody", 
  "structparents", "structbody", "operatorOr", "operatorAnd", "operatorComparison", 
  "operatorStrcat", "operatorAddSub", "operatorMulDivMod", "operatorBitwise", 
  "operatorUnary", "operatorPower", "operatorMathAffectation", "number", 
  "string", "list"
};

std::vector<std::string> KafeParser::_literalNames = {
  "", "'='", "':'", "'('", "')'", "'nonlocal'", "'for'", "'in'", "'do'", 
  "'end'", "'if'", "'then'", "'elif'", "'else'", "'while'", "'fun'", "'->'", 
  "'Obj'", "'ret'", "'dyn'", "'cst'", "'string'", "'int'", "'double'", "'list'", 
  "'bool'", "','", "'.'", "'nil'", "'false'", "'true'", "'or'", "'and'", 
  "'<'", "'>'", "'<='", "'>='", "'!='", "'=='", "'..'", "'+'", "'-'", "'*'", 
  "'/'", "'%'", "'//'", "'&'", "'|'", "'~'", "'<<'", "'>>'", "'^'", "'not'", 
  "'**'", "'+='", "'-='", "'*='", "'/='", "'%='", "'**='", "'..='", "'&='", 
  "'|='", "'<<='", "'>>='", "'^='", "'['", "']'"
};

std::vector<std::string> KafeParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "NAME", "NORMALSTRING", 
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
    0x3, 0x4e, 0x136, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x3, 0x7, 0x3, 0x3f, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x42, 0xb, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x4f, 0xa, 0x4, 
    0xc, 0x4, 0xe, 0x4, 0x52, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x71, 0xa, 0x4, 
    0xc, 0x4, 0xe, 0x4, 0x74, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x78, 
    0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
    0x8d, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x91, 0xa, 0x4, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x9f, 0xa, 0x7, 0x3, 
    0x8, 0x3, 0x8, 0x5, 0x8, 0xa3, 0xa, 0x8, 0x3, 0x8, 0x7, 0x8, 0xa6, 0xa, 
    0x8, 0xc, 0x8, 0xe, 0x8, 0xa9, 0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 
    0xad, 0xa, 0x9, 0x3, 0x9, 0x7, 0x9, 0xb0, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 
    0xb3, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xb9, 
    0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xbd, 0xa, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x7, 0xb, 0xc1, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xc4, 0xb, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x5, 0xc, 0xd5, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x7, 0xc, 0xf7, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xfa, 0xb, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x101, 0xa, 0xd, 0x7, 
    0xd, 0x103, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x106, 0xb, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 
    0x10f, 0xa, 0xf, 0x3, 0xf, 0x7, 0xf, 0x112, 0xa, 0xf, 0xc, 0xf, 0xe, 
    0xf, 0x115, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 
    0x1d, 0x3, 0x1d, 0x2, 0x3, 0x16, 0x1e, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
    0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 
    0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x2, 0xb, 
    0x3, 0x2, 0x15, 0x16, 0x3, 0x2, 0x23, 0x28, 0x3, 0x2, 0x2a, 0x2b, 0x3, 
    0x2, 0x2c, 0x2f, 0x3, 0x2, 0x30, 0x35, 0x5, 0x2, 0x2b, 0x2b, 0x32, 0x32, 
    0x36, 0x36, 0x3, 0x2, 0x38, 0x43, 0x3, 0x2, 0x49, 0x4c, 0x3, 0x2, 0x47, 
    0x48, 0x2, 0x14a, 0x2, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x4, 0x40, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x90, 0x3, 0x2, 0x2, 0x2, 0x8, 0x92, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x95, 0x3, 0x2, 0x2, 0x2, 0xc, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xe, 0xa0, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0xaa, 0x3, 0x2, 0x2, 0x2, 0x12, 0xb4, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0xbc, 0x3, 0x2, 0x2, 0x2, 0x16, 0xd4, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x109, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x116, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x119, 0x3, 0x2, 0x2, 0x2, 0x22, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x11d, 0x3, 0x2, 0x2, 0x2, 0x26, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x28, 0x121, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x123, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x125, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x127, 0x3, 0x2, 0x2, 0x2, 0x30, 0x129, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x34, 0x12d, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x38, 0x131, 0x3, 0x2, 0x2, 0x2, 
    0x3a, 0x3b, 0x5, 0x4, 0x3, 0x2, 0x3b, 0x3c, 0x7, 0x2, 0x2, 0x3, 0x3c, 
    0x3, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3f, 0x5, 0x6, 0x4, 0x2, 0x3e, 0x3d, 
    0x3, 0x2, 0x2, 0x2, 0x3f, 0x42, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3e, 0x3, 
    0x2, 0x2, 0x2, 0x40, 0x41, 0x3, 0x2, 0x2, 0x2, 0x41, 0x5, 0x3, 0x2, 
    0x2, 0x2, 0x42, 0x40, 0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x5, 0xa, 0x6, 
    0x2, 0x44, 0x45, 0x7, 0x46, 0x2, 0x2, 0x45, 0x46, 0x7, 0x3, 0x2, 0x2, 
    0x46, 0x47, 0x5, 0x10, 0x9, 0x2, 0x47, 0x91, 0x3, 0x2, 0x2, 0x2, 0x48, 
    0x49, 0x5, 0xa, 0x6, 0x2, 0x49, 0x4a, 0x7, 0x46, 0x2, 0x2, 0x4a, 0x4b, 
    0x7, 0x4, 0x2, 0x2, 0x4b, 0x4c, 0x7, 0x46, 0x2, 0x2, 0x4c, 0x50, 0x7, 
    0x5, 0x2, 0x2, 0x4d, 0x4f, 0x5, 0x10, 0x9, 0x2, 0x4e, 0x4d, 0x3, 0x2, 
    0x2, 0x2, 0x4f, 0x52, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4e, 0x3, 0x2, 0x2, 
    0x2, 0x50, 0x51, 0x3, 0x2, 0x2, 0x2, 0x51, 0x53, 0x3, 0x2, 0x2, 0x2, 
    0x52, 0x50, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x7, 0x6, 0x2, 0x2, 0x54, 
    0x91, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x7, 0x7, 0x2, 0x2, 0x56, 0x91, 
    0x5, 0xe, 0x8, 0x2, 0x57, 0x58, 0x7, 0x46, 0x2, 0x2, 0x58, 0x59, 0x7, 
    0x3, 0x2, 0x2, 0x59, 0x91, 0x5, 0x10, 0x9, 0x2, 0x5a, 0x5b, 0x7, 0x46, 
    0x2, 0x2, 0x5b, 0x5c, 0x5, 0x32, 0x1a, 0x2, 0x5c, 0x5d, 0x5, 0x10, 0x9, 
    0x2, 0x5d, 0x91, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x91, 0x5, 0x14, 0xb, 0x2, 
    0x5f, 0x60, 0x7, 0x8, 0x2, 0x2, 0x60, 0x61, 0x7, 0x46, 0x2, 0x2, 0x61, 
    0x62, 0x7, 0x9, 0x2, 0x2, 0x62, 0x63, 0x5, 0x16, 0xc, 0x2, 0x63, 0x64, 
    0x7, 0xa, 0x2, 0x2, 0x64, 0x65, 0x5, 0x4, 0x3, 0x2, 0x65, 0x66, 0x7, 
    0xb, 0x2, 0x2, 0x66, 0x91, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x7, 0xc, 
    0x2, 0x2, 0x68, 0x69, 0x5, 0x16, 0xc, 0x2, 0x69, 0x6a, 0x7, 0xd, 0x2, 
    0x2, 0x6a, 0x72, 0x5, 0x4, 0x3, 0x2, 0x6b, 0x6c, 0x7, 0xe, 0x2, 0x2, 
    0x6c, 0x6d, 0x5, 0x16, 0xc, 0x2, 0x6d, 0x6e, 0x7, 0xd, 0x2, 0x2, 0x6e, 
    0x6f, 0x5, 0x4, 0x3, 0x2, 0x6f, 0x71, 0x3, 0x2, 0x2, 0x2, 0x70, 0x6b, 
    0x3, 0x2, 0x2, 0x2, 0x71, 0x74, 0x3, 0x2, 0x2, 0x2, 0x72, 0x70, 0x3, 
    0x2, 0x2, 0x2, 0x72, 0x73, 0x3, 0x2, 0x2, 0x2, 0x73, 0x77, 0x3, 0x2, 
    0x2, 0x2, 0x74, 0x72, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x7, 0xf, 0x2, 
    0x2, 0x76, 0x78, 0x5, 0x4, 0x3, 0x2, 0x77, 0x75, 0x3, 0x2, 0x2, 0x2, 
    0x77, 0x78, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x3, 0x2, 0x2, 0x2, 0x79, 
    0x7a, 0x7, 0xb, 0x2, 0x2, 0x7a, 0x91, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 
    0x7, 0x10, 0x2, 0x2, 0x7c, 0x7d, 0x5, 0x16, 0xc, 0x2, 0x7d, 0x7e, 0x7, 
    0xa, 0x2, 0x2, 0x7e, 0x7f, 0x5, 0x4, 0x3, 0x2, 0x7f, 0x80, 0x7, 0xb, 
    0x2, 0x2, 0x80, 0x91, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x7, 0x11, 0x2, 
    0x2, 0x82, 0x83, 0x7, 0x46, 0x2, 0x2, 0x83, 0x84, 0x5, 0x18, 0xd, 0x2, 
    0x84, 0x85, 0x7, 0x12, 0x2, 0x2, 0x85, 0x86, 0x5, 0xc, 0x7, 0x2, 0x86, 
    0x87, 0x5, 0x1a, 0xe, 0x2, 0x87, 0x91, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 
    0x7, 0x13, 0x2, 0x2, 0x89, 0x8c, 0x7, 0x46, 0x2, 0x2, 0x8a, 0x8b, 0x7, 
    0x4, 0x2, 0x2, 0x8b, 0x8d, 0x5, 0x1c, 0xf, 0x2, 0x8c, 0x8a, 0x3, 0x2, 
    0x2, 0x2, 0x8c, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x3, 0x2, 0x2, 
    0x2, 0x8e, 0x91, 0x5, 0x1e, 0x10, 0x2, 0x8f, 0x91, 0x5, 0x12, 0xa, 0x2, 
    0x90, 0x43, 0x3, 0x2, 0x2, 0x2, 0x90, 0x48, 0x3, 0x2, 0x2, 0x2, 0x90, 
    0x55, 0x3, 0x2, 0x2, 0x2, 0x90, 0x57, 0x3, 0x2, 0x2, 0x2, 0x90, 0x5a, 
    0x3, 0x2, 0x2, 0x2, 0x90, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x90, 0x5f, 0x3, 
    0x2, 0x2, 0x2, 0x90, 0x67, 0x3, 0x2, 0x2, 0x2, 0x90, 0x7b, 0x3, 0x2, 
    0x2, 0x2, 0x90, 0x81, 0x3, 0x2, 0x2, 0x2, 0x90, 0x88, 0x3, 0x2, 0x2, 
    0x2, 0x90, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x91, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x92, 0x93, 0x7, 0x14, 0x2, 0x2, 0x93, 0x94, 0x5, 0x16, 0xc, 0x2, 0x94, 
    0x9, 0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x9, 0x2, 0x2, 0x2, 0x96, 0xb, 
    0x3, 0x2, 0x2, 0x2, 0x97, 0x9f, 0x7, 0x17, 0x2, 0x2, 0x98, 0x9f, 0x7, 
    0x18, 0x2, 0x2, 0x99, 0x9f, 0x7, 0x19, 0x2, 0x2, 0x9a, 0x9f, 0x7, 0x1a, 
    0x2, 0x2, 0x9b, 0x9f, 0x7, 0x1b, 0x2, 0x2, 0x9c, 0x9d, 0x7, 0x13, 0x2, 
    0x2, 0x9d, 0x9f, 0x7, 0x46, 0x2, 0x2, 0x9e, 0x97, 0x3, 0x2, 0x2, 0x2, 
    0x9e, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9e, 
    0x9a, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9c, 
    0x3, 0x2, 0x2, 0x2, 0x9f, 0xd, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa7, 0x7, 
    0x46, 0x2, 0x2, 0xa1, 0xa3, 0x7, 0x1c, 0x2, 0x2, 0xa2, 0xa1, 0x3, 0x2, 
    0x2, 0x2, 0xa2, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x3, 0x2, 0x2, 
    0x2, 0xa4, 0xa6, 0x7, 0x46, 0x2, 0x2, 0xa5, 0xa2, 0x3, 0x2, 0x2, 0x2, 
    0xa6, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa7, 
    0xa8, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xf, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xa7, 
    0x3, 0x2, 0x2, 0x2, 0xaa, 0xb1, 0x5, 0x16, 0xc, 0x2, 0xab, 0xad, 0x7, 
    0x1c, 0x2, 0x2, 0xac, 0xab, 0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 0x3, 0x2, 
    0x2, 0x2, 0xad, 0xae, 0x3, 0x2, 0x2, 0x2, 0xae, 0xb0, 0x5, 0x16, 0xc, 
    0x2, 0xaf, 0xac, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb3, 0x3, 0x2, 0x2, 0x2, 
    0xb1, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb2, 
    0x11, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb5, 
    0x7, 0x46, 0x2, 0x2, 0xb5, 0xb8, 0x7, 0x1d, 0x2, 0x2, 0xb6, 0xb9, 0x7, 
    0x46, 0x2, 0x2, 0xb7, 0xb9, 0x5, 0x12, 0xa, 0x2, 0xb8, 0xb6, 0x3, 0x2, 
    0x2, 0x2, 0xb8, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb9, 0x13, 0x3, 0x2, 0x2, 
    0x2, 0xba, 0xbd, 0x7, 0x46, 0x2, 0x2, 0xbb, 0xbd, 0x5, 0x12, 0xa, 0x2, 
    0xbc, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbd, 
    0xbe, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xc2, 0x7, 0x5, 0x2, 0x2, 0xbf, 0xc1, 
    0x5, 0x10, 0x9, 0x2, 0xc0, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc4, 0x3, 
    0x2, 0x2, 0x2, 0xc2, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x3, 0x2, 
    0x2, 0x2, 0xc3, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc2, 0x3, 0x2, 0x2, 
    0x2, 0xc5, 0xc6, 0x7, 0x6, 0x2, 0x2, 0xc6, 0x15, 0x3, 0x2, 0x2, 0x2, 
    0xc7, 0xc8, 0x8, 0xc, 0x1, 0x2, 0xc8, 0xd5, 0x7, 0x1e, 0x2, 0x2, 0xc9, 
    0xd5, 0x7, 0x1f, 0x2, 0x2, 0xca, 0xd5, 0x7, 0x20, 0x2, 0x2, 0xcb, 0xd5, 
    0x5, 0x34, 0x1b, 0x2, 0xcc, 0xd5, 0x5, 0x36, 0x1c, 0x2, 0xcd, 0xd5, 
    0x5, 0x38, 0x1d, 0x2, 0xce, 0xd5, 0x7, 0x46, 0x2, 0x2, 0xcf, 0xd5, 0x5, 
    0x14, 0xb, 0x2, 0xd0, 0xd5, 0x5, 0x12, 0xa, 0x2, 0xd1, 0xd2, 0x5, 0x2e, 
    0x18, 0x2, 0xd2, 0xd3, 0x5, 0x16, 0xc, 0xa, 0xd3, 0xd5, 0x3, 0x2, 0x2, 
    0x2, 0xd4, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xc9, 0x3, 0x2, 0x2, 0x2, 
    0xd4, 0xca, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xd4, 
    0xcc, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xce, 
    0x3, 0x2, 0x2, 0x2, 0xd4, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd0, 0x3, 
    0x2, 0x2, 0x2, 0xd4, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xf8, 0x3, 0x2, 
    0x2, 0x2, 0xd6, 0xd7, 0xc, 0xb, 0x2, 0x2, 0xd7, 0xd8, 0x5, 0x30, 0x19, 
    0x2, 0xd8, 0xd9, 0x5, 0x16, 0xc, 0xb, 0xd9, 0xf7, 0x3, 0x2, 0x2, 0x2, 
    0xda, 0xdb, 0xc, 0x9, 0x2, 0x2, 0xdb, 0xdc, 0x5, 0x2a, 0x16, 0x2, 0xdc, 
    0xdd, 0x5, 0x16, 0xc, 0xa, 0xdd, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 
    0xc, 0x8, 0x2, 0x2, 0xdf, 0xe0, 0x5, 0x28, 0x15, 0x2, 0xe0, 0xe1, 0x5, 
    0x16, 0xc, 0x9, 0xe1, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0xc, 0x7, 
    0x2, 0x2, 0xe3, 0xe4, 0x5, 0x26, 0x14, 0x2, 0xe4, 0xe5, 0x5, 0x16, 0xc, 
    0x7, 0xe5, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe7, 0xc, 0x6, 0x2, 0x2, 
    0xe7, 0xe8, 0x5, 0x24, 0x13, 0x2, 0xe8, 0xe9, 0x5, 0x16, 0xc, 0x7, 0xe9, 
    0xf7, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 0xc, 0x5, 0x2, 0x2, 0xeb, 0xec, 
    0x5, 0x22, 0x12, 0x2, 0xec, 0xed, 0x5, 0x16, 0xc, 0x6, 0xed, 0xf7, 0x3, 
    0x2, 0x2, 0x2, 0xee, 0xef, 0xc, 0x4, 0x2, 0x2, 0xef, 0xf0, 0x5, 0x20, 
    0x11, 0x2, 0xf0, 0xf1, 0x5, 0x16, 0xc, 0x5, 0xf1, 0xf7, 0x3, 0x2, 0x2, 
    0x2, 0xf2, 0xf3, 0xc, 0x3, 0x2, 0x2, 0xf3, 0xf4, 0x5, 0x2c, 0x17, 0x2, 
    0xf4, 0xf5, 0x5, 0x16, 0xc, 0x4, 0xf5, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf6, 
    0xd6, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xda, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xde, 
    0x3, 0x2, 0x2, 0x2, 0xf6, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xe6, 0x3, 
    0x2, 0x2, 0x2, 0xf6, 0xea, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xee, 0x3, 0x2, 
    0x2, 0x2, 0xf6, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xfa, 0x3, 0x2, 0x2, 
    0x2, 0xf8, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x3, 0x2, 0x2, 0x2, 
    0xf9, 0x17, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xfb, 
    0x104, 0x7, 0x5, 0x2, 0x2, 0xfc, 0xfd, 0x7, 0x46, 0x2, 0x2, 0xfd, 0xfe, 
    0x7, 0x4, 0x2, 0x2, 0xfe, 0x100, 0x5, 0xc, 0x7, 0x2, 0xff, 0x101, 0x7, 
    0x1c, 0x2, 0x2, 0x100, 0xff, 0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 0x3, 
    0x2, 0x2, 0x2, 0x101, 0x103, 0x3, 0x2, 0x2, 0x2, 0x102, 0xfc, 0x3, 0x2, 
    0x2, 0x2, 0x103, 0x106, 0x3, 0x2, 0x2, 0x2, 0x104, 0x102, 0x3, 0x2, 
    0x2, 0x2, 0x104, 0x105, 0x3, 0x2, 0x2, 0x2, 0x105, 0x107, 0x3, 0x2, 
    0x2, 0x2, 0x106, 0x104, 0x3, 0x2, 0x2, 0x2, 0x107, 0x108, 0x7, 0x6, 
    0x2, 0x2, 0x108, 0x19, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10a, 0x5, 0x4, 0x3, 
    0x2, 0x10a, 0x10b, 0x5, 0x8, 0x5, 0x2, 0x10b, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0x10c, 0x113, 0x7, 0x46, 0x2, 0x2, 0x10d, 0x10f, 0x7, 0x1c, 0x2, 0x2, 
    0x10e, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 0x3, 0x2, 0x2, 0x2, 
    0x10f, 0x110, 0x3, 0x2, 0x2, 0x2, 0x110, 0x112, 0x7, 0x46, 0x2, 0x2, 
    0x111, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x112, 0x115, 0x3, 0x2, 0x2, 0x2, 
    0x113, 0x111, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 0x3, 0x2, 0x2, 0x2, 
    0x114, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x115, 0x113, 0x3, 0x2, 0x2, 0x2, 0x116, 
    0x117, 0x5, 0x4, 0x3, 0x2, 0x117, 0x118, 0x7, 0xb, 0x2, 0x2, 0x118, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 0x7, 0x21, 0x2, 0x2, 0x11a, 
    0x21, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 0x7, 0x22, 0x2, 0x2, 0x11c, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11e, 0x9, 0x3, 0x2, 0x2, 0x11e, 0x25, 
    0x3, 0x2, 0x2, 0x2, 0x11f, 0x120, 0x7, 0x29, 0x2, 0x2, 0x120, 0x27, 
    0x3, 0x2, 0x2, 0x2, 0x121, 0x122, 0x9, 0x4, 0x2, 0x2, 0x122, 0x29, 0x3, 
    0x2, 0x2, 0x2, 0x123, 0x124, 0x9, 0x5, 0x2, 0x2, 0x124, 0x2b, 0x3, 0x2, 
    0x2, 0x2, 0x125, 0x126, 0x9, 0x6, 0x2, 0x2, 0x126, 0x2d, 0x3, 0x2, 0x2, 
    0x2, 0x127, 0x128, 0x9, 0x7, 0x2, 0x2, 0x128, 0x2f, 0x3, 0x2, 0x2, 0x2, 
    0x129, 0x12a, 0x7, 0x37, 0x2, 0x2, 0x12a, 0x31, 0x3, 0x2, 0x2, 0x2, 
    0x12b, 0x12c, 0x9, 0x8, 0x2, 0x2, 0x12c, 0x33, 0x3, 0x2, 0x2, 0x2, 0x12d, 
    0x12e, 0x9, 0x9, 0x2, 0x2, 0x12e, 0x35, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x130, 
    0x9, 0xa, 0x2, 0x2, 0x130, 0x37, 0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x7, 
    0x44, 0x2, 0x2, 0x132, 0x133, 0x5, 0x10, 0x9, 0x2, 0x133, 0x134, 0x7, 
    0x45, 0x2, 0x2, 0x134, 0x39, 0x3, 0x2, 0x2, 0x2, 0x17, 0x40, 0x50, 0x72, 
    0x77, 0x8c, 0x90, 0x9e, 0xa2, 0xa7, 0xac, 0xb1, 0xb8, 0xbc, 0xc2, 0xd4, 
    0xf6, 0xf8, 0x100, 0x104, 0x10e, 0x113, 
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
