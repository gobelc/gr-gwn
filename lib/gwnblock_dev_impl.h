/* -*- c++ -*- */
/* 
 * Copyright 2018 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_GWNCPPVGB_GWNBLOCK_DEV_IMPL_H
#define INCLUDED_GWNCPPVGB_GWNBLOCK_DEV_IMPL_H

#include <gwncppvgb/gwnblock_dev.h>

/*  GWN inclusions */
#include <vector>
//#include <gwncppvgb/gwnblock_dev_pdata.h>


namespace gr {
  namespace gwncppvgb {

    /*
     * Please consider some comments // and <text thus enclosed>
     * will be substituted by the gwn_modtool.sh script when
     * creating a new type of block. DO NOT ALTER, the script
     * needs those comments for correct substitution.
     */


    /* GWN gwnblock_dev, a template block */

    class gwnblock_dev_impl : public virtual gwnblock_dev
    {
    private:

      /* GWN ports, nested classes */
      class GWNPort
      {
        protected:
          bool d_debug;
        public:
          GWNPort();
          gwnblock_dev_impl * d_block;
          std::string d_port;
          int d_port_nr;
          std::string __str__();
      }; 
      class GWNOutPort: public virtual GWNPort { 
        public:
          GWNOutPort(gwnblock_dev_impl *, std::string, int);
       };
      class GWNInPort: public virtual GWNPort {
        public:
          GWNInPort(gwnblock_dev_impl *, std::string, int);
      }; 



      /* GWN timers, nested class */


      /** GWN Timer, a timer with message, period, and count.
       
      A nested class implementing a timer which can be instantiated
      in a GWN block to receive internal messages periodically 
      for a number of times.
 
      The block containing the timer receives messages from the timer in an internal port. This internal port, called a timer port, is a message port of the block, but it is not no connected to any external block. All timers in the block send their messages to this unique timer port.

      When started, the timer waits for the indicated period of time before emitting its first message. Then, the timer goes on sending messages after each period of time, until reaching the number of messages indicated as a count parameter. Once the count has been reached, no more messages are sent, and the timer thread is terminated.

      The timer can be suspended in its emission of messages. When suspended, the timer does not emit messages, and the counter is not incremented, but the timer thread remains alive. When taken out from suspension, messages continue to be emitted and the counter incremented from its last value.

      The counter can be resetted, thus starting to emit messages as if it was recently started.
 
      The timer can be stopped before reaching its assigned number of messages to emit. In this case, no messages are emitted any more, and the timer thread is terminated.

      The message emmited by the timer is a tuple containing the type of emitting port as "timer_port", an integer indicating which timer port is the emitter for cases where a block contains several timers, a counter indicating the sequence number of message emitted, and a custom message defined by the user, in PMT format, which allows a great flexibility for the content to be transmitted. Each message is passed to the main block function process_data, where the tasks defined by the programmer of the block to which the timer is attached are performed. In this way, the programmer of the process_data function can identify unambiguously the message origin (a timer), the particular timer whch emitted the message, the sequence number of the message, and a possibly complex structure of data in the custom PMT message.
      */
      class GWNTimer
      {
        protected:
          bool d_debug;

        public:

          /** \brief GWNTimer, constructor.

          @param p_block A pointer to the block having the timer.
          @param p_id_timer An integer identifying the timer.
          @param p_pmt_msg Custom message to emit, in PMT format.
          @param p_counter The number of times to emit the message.
          @param p_period_ms: Tne period of emission in milliseconds.
          */
          GWNTimer(gwnblock_dev_impl * p_block, 
            std::string p_id_timer, pmt::pmt_t p_pmt_msg, 
            int p_count, float p_period_ms);

            gwnblock_dev_impl * d_block;
            std::string d_id_timer; 
            pmt::pmt_t d_pmt_msg;
            int d_counter;
            int d_count;  /** Counts emitted messages. */
            float d_period_ms;
            bool d_suspend; /** If true timer is suspendend. */
            pmt::pmt_t d_pmt_timer_port = pmt::mp("timer_port"); /** a port to receive messages from all timers. */

            /** The timer thread. */
            boost::shared_ptr<gr::thread::thread> d_thread;
            /** Creates thread, timer starts immediately. */
            void start_timer();
            /** Suspends or continues emission of messages. */
            void set_suspend(bool on_off)  { d_suspend = on_off; }
            /** Sets or resets the counter, to 0 or other value. */
            void set_count(int counter)  { d_counter = counter; }
            /** Stops timer and terminates thread. */
            void timer_stop();

            /** \brief The function to run from the timer thread. */
            void run_timer();

      };   // end class GWNTimer


      /** Block specific actions.

      */

      /** Handles timer messages */
      void handle_timer_msg (pmt::pmt_t pmt_msg);

      // GWN user arguments declaration
      std::string d_message;
      int d_counter;

      /** A pointer to the associated pdata object. */
      //gwnblock_dev_pdata * pdata_obj;

    public:
      gwnblock_dev_impl(std::string message, int counter);
      ~gwnblock_dev_impl();

      /* GWN attributes and functions */
      std::string d_name;
      int d_number_in, d_number_out, d_number_timers;
      std::vector<GWNOutPort *> d_ports_out; 
      std::vector<GWNInPort *> d_ports_in;
      std::vector<GWNTimer *> d_timers;
      bool d_debug;
      void post_message(pmt::pmt_t, pmt::pmt_t);
      void handle_msg(pmt::pmt_t);
      std::string __str__();


      /** REWRITE: specific initialization for a new block.

      This function is invoked at the end of the block constructor to account for additional initialization required to perform the specific actions of the  new block, such as timers initialization. 
      */
      void added_init();


      /** REWRITE: actions to perform on received message.

      This function receives messages from the input ports and from the timer ports. Origin of messages, i.e. specific input port or timer port, can be recognized in the port parameter. An optional counter can be included, generally used to indicate the sequence number of the message received. 
      @param p_port The port identifier on which the message was received.
      @param p_pmt_msg The message, in PMT format.
      @param p_counter An optional integer number, for individual message identifier through sequence numbers.
      @return A PMT tuple of (port, message) for the main block to emit.
      */
      pmt::pmt_t process_data(
        std::string p_port, pmt::pmt_t p_pmt_msg, int p_counter);
    


    }; 

  } // namespace gwncppvgb
} // namespace gr

#endif /* INCLUDED_GWNCPPVGB_GWNBLOCK_DEV_IMPL_H */

