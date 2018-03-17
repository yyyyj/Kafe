
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
    setState(54);
    block();
    setState(55);
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
    setState(60);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << KafeParser::T__4)
      | (1ULL << KafeParser::T__5)
      | (1ULL << KafeParser::T__9)
      | (1ULL << KafeParser::T__13)
      | (1ULL << KafeParser::T__14)
      | (1ULL << KafeParser::T__16)
      | (1ULL << KafeParser::T__18)
      | (1ULL << KafeParser::T__19))) != 0) || _la == KafeParser::NAME) {
      setState(57);
      stat();
      setState(62);
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
    setState(136);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(63);
      varqualifier();
      setState(64);
      match(KafeParser::NAME);
      setState(65);
      match(KafeParser::T__0);
      setState(66);
      explist();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(68);
      varqualifier();
      setState(69);
      match(KafeParser::NAME);
      setState(70);
      match(KafeParser::T__1);
      setState(71);
      match(KafeParser::NAME);
      setState(72);
      match(KafeParser::T__2);
      setState(76);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (((((_la - 29) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 29)) & ((1ULL << (KafeParser::T__28 - 29))
        | (1ULL << (KafeParser::T__29 - 29))
        | (1ULL << (KafeParser::T__30 - 29))
        | (1ULL << (KafeParser::T__41 - 29))
        | (1ULL << (KafeParser::T__48 - 29))
        | (1ULL << (KafeParser::T__52 - 29))
        | (1ULL << (KafeParser::T__66 - 29))
        | (1ULL << (KafeParser::NAME - 29))
        | (1ULL << (KafeParser::NORMALSTRING - 29))
        | (1ULL << (KafeParser::CHARSTRING - 29))
        | (1ULL << (KafeParser::INT - 29))
        | (1ULL << (KafeParser::HEX - 29))
        | (1ULL << (KafeParser::FLOAT - 29))
        | (1ULL << (KafeParser::HEX_FLOAT - 29)))) != 0)) {
        setState(73);
        explist();
        setState(78);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(79);
      match(KafeParser::T__3);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(81);
      match(KafeParser::T__4);
      setState(82);
      namelist();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(83);
      match(KafeParser::NAME);
      setState(84);
      match(KafeParser::T__0);
      setState(85);
      explist();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(86);
      match(KafeParser::NAME);
      setState(87);
      operatorMathAffectation();
      setState(88);
      explist();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(90);
      functioncall();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(91);
      match(KafeParser::T__5);
      setState(92);
      match(KafeParser::NAME);
      setState(93);
      match(KafeParser::T__6);
      setState(94);
      exp(0);
      setState(95);
      match(KafeParser::T__7);
      setState(96);
      block();
      setState(97);
      match(KafeParser::T__8);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(99);
      match(KafeParser::T__9);
      setState(100);
      exp(0);
      setState(101);
      match(KafeParser::T__10);
      setState(102);
      block();
      setState(110);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == KafeParser::T__11) {
        setState(103);
        match(KafeParser::T__11);
        setState(104);
        exp(0);
        setState(105);
        match(KafeParser::T__10);
        setState(106);
        block();
        setState(112);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(115);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == KafeParser::T__12) {
        setState(113);
        match(KafeParser::T__12);
        setState(114);
        block();
      }
      setState(117);
      match(KafeParser::T__8);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(119);
      match(KafeParser::T__13);
      setState(120);
      exp(0);
      setState(121);
      match(KafeParser::T__7);
      setState(122);
      block();
      setState(123);
      match(KafeParser::T__8);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(125);
      match(KafeParser::T__14);
      setState(126);
      match(KafeParser::NAME);
      setState(127);
      argslist();
      setState(128);
      match(KafeParser::T__15);
      setState(129);
      type();
      setState(130);
      funcbody();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(132);
      match(KafeParser::T__16);
      setState(133);
      match(KafeParser::NAME);
      setState(134);
      structbody();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(135);
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
    setState(138);
    match(KafeParser::T__17);
    setState(139);
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
    setState(141);
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
    setState(150);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case KafeParser::T__20: {
        enterOuterAlt(_localctx, 1);
        setState(143);
        match(KafeParser::T__20);
        break;
      }

      case KafeParser::T__21: {
        enterOuterAlt(_localctx, 2);
        setState(144);
        match(KafeParser::T__21);
        break;
      }

      case KafeParser::T__22: {
        enterOuterAlt(_localctx, 3);
        setState(145);
        match(KafeParser::T__22);
        break;
      }

      case KafeParser::T__23: {
        enterOuterAlt(_localctx, 4);
        setState(146);
        match(KafeParser::T__23);
        break;
      }

      case KafeParser::T__24: {
        enterOuterAlt(_localctx, 5);
        setState(147);
        match(KafeParser::T__24);
        break;
      }

      case KafeParser::T__25: {
        enterOuterAlt(_localctx, 6);
        setState(148);
        match(KafeParser::T__25);
        setState(149);
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
    setState(152);
    match(KafeParser::NAME);
    setState(159);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(154);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == KafeParser::T__26) {
          setState(153);
          match(KafeParser::T__26);
        }
        setState(156);
        match(KafeParser::NAME); 
      }
      setState(161);
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
    setState(162);
    exp(0);
    setState(169);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(164);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == KafeParser::T__26) {
          setState(163);
          match(KafeParser::T__26);
        }
        setState(166);
        exp(0); 
      }
      setState(171);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
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
    setState(172);
    match(KafeParser::NAME);
    setState(173);
    match(KafeParser::T__27);
    setState(176);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(174);
      match(KafeParser::NAME);
      break;
    }

    case 2: {
      setState(175);
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
    setState(180);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(178);
      match(KafeParser::NAME);
      break;
    }

    case 2: {
      setState(179);
      getstructmember();
      break;
    }

    }
    setState(182);
    match(KafeParser::T__2);
    setState(186);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 29) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 29)) & ((1ULL << (KafeParser::T__28 - 29))
      | (1ULL << (KafeParser::T__29 - 29))
      | (1ULL << (KafeParser::T__30 - 29))
      | (1ULL << (KafeParser::T__41 - 29))
      | (1ULL << (KafeParser::T__48 - 29))
      | (1ULL << (KafeParser::T__52 - 29))
      | (1ULL << (KafeParser::T__66 - 29))
      | (1ULL << (KafeParser::NAME - 29))
      | (1ULL << (KafeParser::NORMALSTRING - 29))
      | (1ULL << (KafeParser::CHARSTRING - 29))
      | (1ULL << (KafeParser::INT - 29))
      | (1ULL << (KafeParser::HEX - 29))
      | (1ULL << (KafeParser::FLOAT - 29))
      | (1ULL << (KafeParser::HEX_FLOAT - 29)))) != 0)) {
      setState(183);
      explist();
      setState(188);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(189);
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
    setState(204);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(192);
      match(KafeParser::T__28);
      break;
    }

    case 2: {
      setState(193);
      match(KafeParser::T__29);
      break;
    }

    case 3: {
      setState(194);
      match(KafeParser::T__30);
      break;
    }

    case 4: {
      setState(195);
      number();
      break;
    }

    case 5: {
      setState(196);
      string();
      break;
    }

    case 6: {
      setState(197);
      list();
      break;
    }

    case 7: {
      setState(198);
      match(KafeParser::NAME);
      break;
    }

    case 8: {
      setState(199);
      functioncall();
      break;
    }

    case 9: {
      setState(200);
      getstructmember();
      break;
    }

    case 10: {
      setState(201);
      operatorUnary();
      setState(202);
      exp(8);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(240);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(238);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(206);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(207);
          operatorPower();
          setState(208);
          exp(9);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(210);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(211);
          operatorMulDivMod();
          setState(212);
          exp(8);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(214);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(215);
          operatorAddSub();
          setState(216);
          exp(7);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(218);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(219);
          operatorStrcat();
          setState(220);
          exp(5);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(222);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(223);
          operatorComparison();
          setState(224);
          exp(5);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(226);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(227);
          operatorAnd();
          setState(228);
          exp(4);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(230);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(231);
          operatorOr();
          setState(232);
          exp(3);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(234);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(235);
          operatorBitwise();
          setState(236);
          exp(2);
          break;
        }

        } 
      }
      setState(242);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
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
    setState(243);
    match(KafeParser::T__2);
    setState(252);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == KafeParser::NAME) {
      setState(244);
      match(KafeParser::NAME);
      setState(245);
      match(KafeParser::T__1);
      setState(246);
      type();
      setState(248);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == KafeParser::T__26) {
        setState(247);
        match(KafeParser::T__26);
      }
      setState(254);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(255);
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
    setState(257);
    block();
    setState(258);
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

antlrcpp::Any KafeParser::StructbodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KafeVisitor*>(visitor))
    return parserVisitor->visitStructbody(this);
  else
    return visitor->visitChildren(this);
}

KafeParser::StructbodyContext* KafeParser::structbody() {
  StructbodyContext *_localctx = _tracker.createInstance<StructbodyContext>(_ctx, getState());
  enterRule(_localctx, 26, KafeParser::RuleStructbody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(260);
    block();
    setState(261);
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
  enterRule(_localctx, 28, KafeParser::RuleOperatorOr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(263);
    match(KafeParser::T__31);
   
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
  enterRule(_localctx, 30, KafeParser::RuleOperatorAnd);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(265);
    match(KafeParser::T__32);
   
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
  enterRule(_localctx, 32, KafeParser::RuleOperatorComparison);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(267);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << KafeParser::T__33)
      | (1ULL << KafeParser::T__34)
      | (1ULL << KafeParser::T__35)
      | (1ULL << KafeParser::T__36)
      | (1ULL << KafeParser::T__37)
      | (1ULL << KafeParser::T__38))) != 0))) {
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
  enterRule(_localctx, 34, KafeParser::RuleOperatorStrcat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(269);
    match(KafeParser::T__39);
   
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
  enterRule(_localctx, 36, KafeParser::RuleOperatorAddSub);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(271);
    _la = _input->LA(1);
    if (!(_la == KafeParser::T__40

    || _la == KafeParser::T__41)) {
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
  enterRule(_localctx, 38, KafeParser::RuleOperatorMulDivMod);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(273);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << KafeParser::T__42)
      | (1ULL << KafeParser::T__43)
      | (1ULL << KafeParser::T__44)
      | (1ULL << KafeParser::T__45))) != 0))) {
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
  enterRule(_localctx, 40, KafeParser::RuleOperatorBitwise);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(275);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << KafeParser::T__46)
      | (1ULL << KafeParser::T__47)
      | (1ULL << KafeParser::T__48)
      | (1ULL << KafeParser::T__49)
      | (1ULL << KafeParser::T__50)
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
  enterRule(_localctx, 42, KafeParser::RuleOperatorUnary);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(277);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << KafeParser::T__41)
      | (1ULL << KafeParser::T__48)
      | (1ULL << KafeParser::T__52))) != 0))) {
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
  enterRule(_localctx, 44, KafeParser::RuleOperatorPower);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(279);
    match(KafeParser::T__53);
   
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
  enterRule(_localctx, 46, KafeParser::RuleOperatorMathAffectation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(281);
    _la = _input->LA(1);
    if (!(((((_la - 55) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 55)) & ((1ULL << (KafeParser::T__54 - 55))
      | (1ULL << (KafeParser::T__55 - 55))
      | (1ULL << (KafeParser::T__56 - 55))
      | (1ULL << (KafeParser::T__57 - 55))
      | (1ULL << (KafeParser::T__58 - 55))
      | (1ULL << (KafeParser::T__59 - 55))
      | (1ULL << (KafeParser::T__60 - 55))
      | (1ULL << (KafeParser::T__61 - 55))
      | (1ULL << (KafeParser::T__62 - 55))
      | (1ULL << (KafeParser::T__63 - 55))
      | (1ULL << (KafeParser::T__64 - 55))
      | (1ULL << (KafeParser::T__65 - 55)))) != 0))) {
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
  enterRule(_localctx, 48, KafeParser::RuleNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(283);
    _la = _input->LA(1);
    if (!(((((_la - 72) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 72)) & ((1ULL << (KafeParser::INT - 72))
      | (1ULL << (KafeParser::HEX - 72))
      | (1ULL << (KafeParser::FLOAT - 72))
      | (1ULL << (KafeParser::HEX_FLOAT - 72)))) != 0))) {
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
  enterRule(_localctx, 50, KafeParser::RuleString);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(285);
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
  enterRule(_localctx, 52, KafeParser::RuleList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(287);
    match(KafeParser::T__66);
    setState(288);
    explist();
    setState(289);
    match(KafeParser::T__67);
   
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
  "structbody", "operatorOr", "operatorAnd", "operatorComparison", "operatorStrcat", 
  "operatorAddSub", "operatorMulDivMod", "operatorBitwise", "operatorUnary", 
  "operatorPower", "operatorMathAffectation", "number", "string", "list"
};

std::vector<std::string> KafeParser::_literalNames = {
  "", "'='", "':'", "'('", "')'", "'nonlocal'", "'for'", "'in'", "'do'", 
  "'end'", "'if'", "'then'", "'elif'", "'else'", "'while'", "'fun'", "'->'", 
  "'Obj'", "'ret'", "'dyn'", "'cst'", "'string'", "'int'", "'double'", "'list'", 
  "'bool'", "'struct'", "','", "'.'", "'nil'", "'false'", "'true'", "'or'", 
  "'and'", "'<'", "'>'", "'<='", "'>='", "'!='", "'=='", "'..'", "'+'", 
  "'-'", "'*'", "'/'", "'%'", "'//'", "'&'", "'|'", "'~'", "'<<'", "'>>'", 
  "'^'", "'not'", "'**'", "'+='", "'-='", "'*='", "'/='", "'%='", "'**='", 
  "'..='", "'&='", "'|='", "'<<='", "'>>='", "'^='", "'['", "']'"
};

std::vector<std::string> KafeParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "NAME", "NORMALSTRING", 
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
    0x3, 0x4f, 0x126, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x7, 0x3, 
    0x3d, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x40, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x4d, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x50, 
    0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x6f, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x72, 
    0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x76, 0xa, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x8b, 0xa, 0x4, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x99, 0xa, 0x7, 0x3, 
    0x8, 0x3, 0x8, 0x5, 0x8, 0x9d, 0xa, 0x8, 0x3, 0x8, 0x7, 0x8, 0xa0, 0xa, 
    0x8, 0xc, 0x8, 0xe, 0x8, 0xa3, 0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 
    0xa7, 0xa, 0x9, 0x3, 0x9, 0x7, 0x9, 0xaa, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 
    0xad, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xb3, 
    0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xb7, 0xa, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x7, 0xb, 0xbb, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xbe, 0xb, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x5, 0xc, 0xcf, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x7, 0xc, 0xf1, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xf4, 0xb, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xfb, 0xa, 0xd, 0x7, 
    0xd, 0xfd, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x100, 0xb, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x2, 0x3, 0x16, 0x1d, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 
    0x2, 0xb, 0x3, 0x2, 0x15, 0x16, 0x3, 0x2, 0x24, 0x29, 0x3, 0x2, 0x2b, 
    0x2c, 0x3, 0x2, 0x2d, 0x30, 0x3, 0x2, 0x31, 0x36, 0x5, 0x2, 0x2c, 0x2c, 
    0x33, 0x33, 0x37, 0x37, 0x3, 0x2, 0x39, 0x44, 0x3, 0x2, 0x4a, 0x4d, 
    0x3, 0x2, 0x48, 0x49, 0x2, 0x138, 0x2, 0x38, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x3e, 0x3, 0x2, 0x2, 0x2, 0x6, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8, 0x8c, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x8f, 0x3, 0x2, 0x2, 0x2, 0xc, 0x98, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x10, 0xa4, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0xae, 0x3, 0x2, 0x2, 0x2, 0x14, 0xb6, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0xce, 0x3, 0x2, 0x2, 0x2, 0x18, 0xf5, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0x103, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x106, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x109, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x22, 0x10d, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x26, 0x111, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0x113, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x115, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0x117, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x119, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x32, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x11f, 0x3, 0x2, 0x2, 0x2, 0x36, 0x121, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 
    0x5, 0x4, 0x3, 0x2, 0x39, 0x3a, 0x7, 0x2, 0x2, 0x3, 0x3a, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x3b, 0x3d, 0x5, 0x6, 0x4, 0x2, 0x3c, 0x3b, 0x3, 0x2, 
    0x2, 0x2, 0x3d, 0x40, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3c, 0x3, 0x2, 0x2, 
    0x2, 0x3e, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x5, 0xa, 0x6, 0x2, 0x42, 
    0x43, 0x7, 0x47, 0x2, 0x2, 0x43, 0x44, 0x7, 0x3, 0x2, 0x2, 0x44, 0x45, 
    0x5, 0x10, 0x9, 0x2, 0x45, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x5, 
    0xa, 0x6, 0x2, 0x47, 0x48, 0x7, 0x47, 0x2, 0x2, 0x48, 0x49, 0x7, 0x4, 
    0x2, 0x2, 0x49, 0x4a, 0x7, 0x47, 0x2, 0x2, 0x4a, 0x4e, 0x7, 0x5, 0x2, 
    0x2, 0x4b, 0x4d, 0x5, 0x10, 0x9, 0x2, 0x4c, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x4d, 0x50, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4e, 
    0x4f, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x51, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4e, 
    0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x7, 0x6, 0x2, 0x2, 0x52, 0x8b, 0x3, 
    0x2, 0x2, 0x2, 0x53, 0x54, 0x7, 0x7, 0x2, 0x2, 0x54, 0x8b, 0x5, 0xe, 
    0x8, 0x2, 0x55, 0x56, 0x7, 0x47, 0x2, 0x2, 0x56, 0x57, 0x7, 0x3, 0x2, 
    0x2, 0x57, 0x8b, 0x5, 0x10, 0x9, 0x2, 0x58, 0x59, 0x7, 0x47, 0x2, 0x2, 
    0x59, 0x5a, 0x5, 0x30, 0x19, 0x2, 0x5a, 0x5b, 0x5, 0x10, 0x9, 0x2, 0x5b, 
    0x8b, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x8b, 0x5, 0x14, 0xb, 0x2, 0x5d, 0x5e, 
    0x7, 0x8, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0x47, 0x2, 0x2, 0x5f, 0x60, 0x7, 
    0x9, 0x2, 0x2, 0x60, 0x61, 0x5, 0x16, 0xc, 0x2, 0x61, 0x62, 0x7, 0xa, 
    0x2, 0x2, 0x62, 0x63, 0x5, 0x4, 0x3, 0x2, 0x63, 0x64, 0x7, 0xb, 0x2, 
    0x2, 0x64, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x7, 0xc, 0x2, 0x2, 
    0x66, 0x67, 0x5, 0x16, 0xc, 0x2, 0x67, 0x68, 0x7, 0xd, 0x2, 0x2, 0x68, 
    0x70, 0x5, 0x4, 0x3, 0x2, 0x69, 0x6a, 0x7, 0xe, 0x2, 0x2, 0x6a, 0x6b, 
    0x5, 0x16, 0xc, 0x2, 0x6b, 0x6c, 0x7, 0xd, 0x2, 0x2, 0x6c, 0x6d, 0x5, 
    0x4, 0x3, 0x2, 0x6d, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x69, 0x3, 0x2, 
    0x2, 0x2, 0x6f, 0x72, 0x3, 0x2, 0x2, 0x2, 0x70, 0x6e, 0x3, 0x2, 0x2, 
    0x2, 0x70, 0x71, 0x3, 0x2, 0x2, 0x2, 0x71, 0x75, 0x3, 0x2, 0x2, 0x2, 
    0x72, 0x70, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x7, 0xf, 0x2, 0x2, 0x74, 
    0x76, 0x5, 0x4, 0x3, 0x2, 0x75, 0x73, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 
    0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x7, 
    0xb, 0x2, 0x2, 0x78, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x10, 
    0x2, 0x2, 0x7a, 0x7b, 0x5, 0x16, 0xc, 0x2, 0x7b, 0x7c, 0x7, 0xa, 0x2, 
    0x2, 0x7c, 0x7d, 0x5, 0x4, 0x3, 0x2, 0x7d, 0x7e, 0x7, 0xb, 0x2, 0x2, 
    0x7e, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x7, 0x11, 0x2, 0x2, 0x80, 
    0x81, 0x7, 0x47, 0x2, 0x2, 0x81, 0x82, 0x5, 0x18, 0xd, 0x2, 0x82, 0x83, 
    0x7, 0x12, 0x2, 0x2, 0x83, 0x84, 0x5, 0xc, 0x7, 0x2, 0x84, 0x85, 0x5, 
    0x1a, 0xe, 0x2, 0x85, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x7, 0x13, 
    0x2, 0x2, 0x87, 0x88, 0x7, 0x47, 0x2, 0x2, 0x88, 0x8b, 0x5, 0x1c, 0xf, 
    0x2, 0x89, 0x8b, 0x5, 0x12, 0xa, 0x2, 0x8a, 0x41, 0x3, 0x2, 0x2, 0x2, 
    0x8a, 0x46, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x53, 0x3, 0x2, 0x2, 0x2, 0x8a, 
    0x55, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x58, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x5c, 
    0x3, 0x2, 0x2, 0x2, 0x8a, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x65, 0x3, 
    0x2, 0x2, 0x2, 0x8a, 0x79, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x7f, 0x3, 0x2, 
    0x2, 0x2, 0x8a, 0x86, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x89, 0x3, 0x2, 0x2, 
    0x2, 0x8b, 0x7, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x7, 0x14, 0x2, 0x2, 
    0x8d, 0x8e, 0x5, 0x16, 0xc, 0x2, 0x8e, 0x9, 0x3, 0x2, 0x2, 0x2, 0x8f, 
    0x90, 0x9, 0x2, 0x2, 0x2, 0x90, 0xb, 0x3, 0x2, 0x2, 0x2, 0x91, 0x99, 
    0x7, 0x17, 0x2, 0x2, 0x92, 0x99, 0x7, 0x18, 0x2, 0x2, 0x93, 0x99, 0x7, 
    0x19, 0x2, 0x2, 0x94, 0x99, 0x7, 0x1a, 0x2, 0x2, 0x95, 0x99, 0x7, 0x1b, 
    0x2, 0x2, 0x96, 0x97, 0x7, 0x1c, 0x2, 0x2, 0x97, 0x99, 0x7, 0x47, 0x2, 
    0x2, 0x98, 0x91, 0x3, 0x2, 0x2, 0x2, 0x98, 0x92, 0x3, 0x2, 0x2, 0x2, 
    0x98, 0x93, 0x3, 0x2, 0x2, 0x2, 0x98, 0x94, 0x3, 0x2, 0x2, 0x2, 0x98, 
    0x95, 0x3, 0x2, 0x2, 0x2, 0x98, 0x96, 0x3, 0x2, 0x2, 0x2, 0x99, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0x9a, 0xa1, 0x7, 0x47, 0x2, 0x2, 0x9b, 0x9d, 0x7, 
    0x1d, 0x2, 0x2, 0x9c, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x3, 0x2, 
    0x2, 0x2, 0x9d, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x9e, 0xa0, 0x7, 0x47, 0x2, 
    0x2, 0x9f, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa3, 0x3, 0x2, 0x2, 0x2, 
    0xa1, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa2, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xab, 
    0x5, 0x16, 0xc, 0x2, 0xa5, 0xa7, 0x7, 0x1d, 0x2, 0x2, 0xa6, 0xa5, 0x3, 
    0x2, 0x2, 0x2, 0xa6, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x3, 0x2, 
    0x2, 0x2, 0xa8, 0xaa, 0x5, 0x16, 0xc, 0x2, 0xa9, 0xa6, 0x3, 0x2, 0x2, 
    0x2, 0xaa, 0xad, 0x3, 0x2, 0x2, 0x2, 0xab, 0xa9, 0x3, 0x2, 0x2, 0x2, 
    0xab, 0xac, 0x3, 0x2, 0x2, 0x2, 0xac, 0x11, 0x3, 0x2, 0x2, 0x2, 0xad, 
    0xab, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x7, 0x47, 0x2, 0x2, 0xaf, 0xb2, 
    0x7, 0x1e, 0x2, 0x2, 0xb0, 0xb3, 0x7, 0x47, 0x2, 0x2, 0xb1, 0xb3, 0x5, 
    0x12, 0xa, 0x2, 0xb2, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb1, 0x3, 0x2, 
    0x2, 0x2, 0xb3, 0x13, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb7, 0x7, 0x47, 0x2, 
    0x2, 0xb5, 0xb7, 0x5, 0x12, 0xa, 0x2, 0xb6, 0xb4, 0x3, 0x2, 0x2, 0x2, 
    0xb6, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb8, 
    0xbc, 0x7, 0x5, 0x2, 0x2, 0xb9, 0xbb, 0x5, 0x10, 0x9, 0x2, 0xba, 0xb9, 
    0x3, 0x2, 0x2, 0x2, 0xbb, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xba, 0x3, 
    0x2, 0x2, 0x2, 0xbc, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbf, 0x3, 0x2, 
    0x2, 0x2, 0xbe, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x7, 0x6, 0x2, 
    0x2, 0xc0, 0x15, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x8, 0xc, 0x1, 0x2, 
    0xc2, 0xcf, 0x7, 0x1f, 0x2, 0x2, 0xc3, 0xcf, 0x7, 0x20, 0x2, 0x2, 0xc4, 
    0xcf, 0x7, 0x21, 0x2, 0x2, 0xc5, 0xcf, 0x5, 0x32, 0x1a, 0x2, 0xc6, 0xcf, 
    0x5, 0x34, 0x1b, 0x2, 0xc7, 0xcf, 0x5, 0x36, 0x1c, 0x2, 0xc8, 0xcf, 
    0x7, 0x47, 0x2, 0x2, 0xc9, 0xcf, 0x5, 0x14, 0xb, 0x2, 0xca, 0xcf, 0x5, 
    0x12, 0xa, 0x2, 0xcb, 0xcc, 0x5, 0x2c, 0x17, 0x2, 0xcc, 0xcd, 0x5, 0x16, 
    0xc, 0xa, 0xcd, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xce, 0xc1, 0x3, 0x2, 0x2, 
    0x2, 0xce, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xce, 0xc4, 0x3, 0x2, 0x2, 0x2, 
    0xce, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xce, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xce, 
    0xc7, 0x3, 0x2, 0x2, 0x2, 0xce, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xce, 0xc9, 
    0x3, 0x2, 0x2, 0x2, 0xce, 0xca, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcb, 0x3, 
    0x2, 0x2, 0x2, 0xcf, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0xc, 0xb, 
    0x2, 0x2, 0xd1, 0xd2, 0x5, 0x2e, 0x18, 0x2, 0xd2, 0xd3, 0x5, 0x16, 0xc, 
    0xb, 0xd3, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0xc, 0x9, 0x2, 0x2, 
    0xd5, 0xd6, 0x5, 0x28, 0x15, 0x2, 0xd6, 0xd7, 0x5, 0x16, 0xc, 0xa, 0xd7, 
    0xf1, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 0xc, 0x8, 0x2, 0x2, 0xd9, 0xda, 
    0x5, 0x26, 0x14, 0x2, 0xda, 0xdb, 0x5, 0x16, 0xc, 0x9, 0xdb, 0xf1, 0x3, 
    0x2, 0x2, 0x2, 0xdc, 0xdd, 0xc, 0x7, 0x2, 0x2, 0xdd, 0xde, 0x5, 0x24, 
    0x13, 0x2, 0xde, 0xdf, 0x5, 0x16, 0xc, 0x7, 0xdf, 0xf1, 0x3, 0x2, 0x2, 
    0x2, 0xe0, 0xe1, 0xc, 0x6, 0x2, 0x2, 0xe1, 0xe2, 0x5, 0x22, 0x12, 0x2, 
    0xe2, 0xe3, 0x5, 0x16, 0xc, 0x7, 0xe3, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xe4, 
    0xe5, 0xc, 0x5, 0x2, 0x2, 0xe5, 0xe6, 0x5, 0x20, 0x11, 0x2, 0xe6, 0xe7, 
    0x5, 0x16, 0xc, 0x6, 0xe7, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 0xc, 
    0x4, 0x2, 0x2, 0xe9, 0xea, 0x5, 0x1e, 0x10, 0x2, 0xea, 0xeb, 0x5, 0x16, 
    0xc, 0x5, 0xeb, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0xc, 0x3, 0x2, 
    0x2, 0xed, 0xee, 0x5, 0x2a, 0x16, 0x2, 0xee, 0xef, 0x5, 0x16, 0xc, 0x4, 
    0xef, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xf0, 
    0xd4, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xdc, 
    0x3, 0x2, 0x2, 0x2, 0xf0, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xe4, 0x3, 
    0x2, 0x2, 0x2, 0xf0, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xec, 0x3, 0x2, 
    0x2, 0x2, 0xf1, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf0, 0x3, 0x2, 0x2, 
    0x2, 0xf2, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf3, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0xf4, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xfe, 0x7, 0x5, 0x2, 0x2, 0xf6, 
    0xf7, 0x7, 0x47, 0x2, 0x2, 0xf7, 0xf8, 0x7, 0x4, 0x2, 0x2, 0xf8, 0xfa, 
    0x5, 0xc, 0x7, 0x2, 0xf9, 0xfb, 0x7, 0x1d, 0x2, 0x2, 0xfa, 0xf9, 0x3, 
    0x2, 0x2, 0x2, 0xfa, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfd, 0x3, 0x2, 
    0x2, 0x2, 0xfc, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xfd, 0x100, 0x3, 0x2, 0x2, 
    0x2, 0xfe, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x3, 0x2, 0x2, 0x2, 
    0xff, 0x101, 0x3, 0x2, 0x2, 0x2, 0x100, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x101, 
    0x102, 0x7, 0x6, 0x2, 0x2, 0x102, 0x19, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 
    0x5, 0x4, 0x3, 0x2, 0x104, 0x105, 0x5, 0x8, 0x5, 0x2, 0x105, 0x1b, 0x3, 
    0x2, 0x2, 0x2, 0x106, 0x107, 0x5, 0x4, 0x3, 0x2, 0x107, 0x108, 0x7, 
    0xb, 0x2, 0x2, 0x108, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10a, 0x7, 0x22, 
    0x2, 0x2, 0x10a, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x10c, 0x7, 0x23, 
    0x2, 0x2, 0x10c, 0x21, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 0x9, 0x3, 0x2, 
    0x2, 0x10e, 0x23, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 0x7, 0x2a, 0x2, 
    0x2, 0x110, 0x25, 0x3, 0x2, 0x2, 0x2, 0x111, 0x112, 0x9, 0x4, 0x2, 0x2, 
    0x112, 0x27, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 0x9, 0x5, 0x2, 0x2, 0x114, 
    0x29, 0x3, 0x2, 0x2, 0x2, 0x115, 0x116, 0x9, 0x6, 0x2, 0x2, 0x116, 0x2b, 
    0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x9, 0x7, 0x2, 0x2, 0x118, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0x119, 0x11a, 0x7, 0x38, 0x2, 0x2, 0x11a, 0x2f, 0x3, 
    0x2, 0x2, 0x2, 0x11b, 0x11c, 0x9, 0x8, 0x2, 0x2, 0x11c, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0x11d, 0x11e, 0x9, 0x9, 0x2, 0x2, 0x11e, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x11f, 0x120, 0x9, 0xa, 0x2, 0x2, 0x120, 0x35, 0x3, 0x2, 0x2, 0x2, 
    0x121, 0x122, 0x7, 0x45, 0x2, 0x2, 0x122, 0x123, 0x5, 0x10, 0x9, 0x2, 
    0x123, 0x124, 0x7, 0x46, 0x2, 0x2, 0x124, 0x37, 0x3, 0x2, 0x2, 0x2, 
    0x14, 0x3e, 0x4e, 0x70, 0x75, 0x8a, 0x98, 0x9c, 0xa1, 0xa6, 0xab, 0xb2, 
    0xb6, 0xbc, 0xce, 0xf0, 0xf2, 0xfa, 0xfe, 
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
