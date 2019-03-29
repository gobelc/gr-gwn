/* -*- c++ -*- */

#define GWNCPPVGB_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "gwncppvgb_swig_doc.i"

%{
#include "gwncppvgb/message_timer_example.h"
#include "gwncppvgb/fsm_test.h"
#include "gwncppvgb/fsmblk.h"
#include "gwncppvgb/gwnmsg_source.h"
#include "gwncppvgb/gwnmsg_sink.h"
#include "gwncppvgb/virtual_channel.h"
#include "gwncppvgb/stop_wait_ack.h"
#include "gwncppvgb/arq_sender.h"
#include "gwncppvgb/arq_sender_fsm.h"
%}


%include "gwncppvgb/message_timer_example.h"
GR_SWIG_BLOCK_MAGIC2(gwncppvgb, message_timer_example);

%include "gwncppvgb/fsm_test.h"
GR_SWIG_BLOCK_MAGIC2(gwncppvgb, fsm_test);
%include "gwncppvgb/fsmblk.h"
%include "gwncppvgb/gwnmsg_source.h"
GR_SWIG_BLOCK_MAGIC2(gwncppvgb, gwnmsg_source);
%include "gwncppvgb/gwnmsg_sink.h"
GR_SWIG_BLOCK_MAGIC2(gwncppvgb, gwnmsg_sink);
%include "gwncppvgb/virtual_channel.h"
GR_SWIG_BLOCK_MAGIC2(gwncppvgb, virtual_channel);
%include "gwncppvgb/stop_wait_ack.h"
GR_SWIG_BLOCK_MAGIC2(gwncppvgb, stop_wait_ack);
%include "gwncppvgb/arq_sender.h"
GR_SWIG_BLOCK_MAGIC2(gwncppvgb, arq_sender);
%include "gwncppvgb/arq_sender_fsm.h"
