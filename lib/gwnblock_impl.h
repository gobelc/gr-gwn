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

#ifndef INCLUDED_GWNCPPVGB_GWNBLOCK_IMPL_H
#define INCLUDED_GWNCPPVGB_GWNBLOCK_IMPL_H

#include <gwncppvgb/gwnblock.h>
#include <vector>

namespace gr {
  namespace gwncppvgb {

    void set_debug(bool);

    class GWNPort;        // forward declaration
    class GWNOutPort;     // forward declaration
    class GWNInPort;      // forward declaration
  


    /* gwnblock */

    class gwnblock_impl : public virtual gwnblock
    {
    private:

    public:
      gwnblock_impl(std::string name, int number_in, int number_out,
        int number_timers, int number_timeouts);
      ~gwnblock_impl();

      // GWN
      std::string name;
      int number_in, number_out, number_timers, number_timeouts;
      std::vector<GWNOutPort *> ports_out; 
      std::vector<GWNInPort *> ports_in;
      void post_message(std::string, std::string);
      void handle_msg(pmt::pmt_t);
      void process_data(std::string);
      std::string __str__();


      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
    };



    /* GWNPort */

    class GWNPort
    {
      protected:
      public:
        GWNPort();
        gwnblock_impl * block;
        std::string port;
        int port_nr;
        std::string __str__();
    }; 


    /* GWNOutPort */

    class GWNOutPort: public virtual GWNPort { 
      public:
        GWNOutPort(gwnblock_impl *, std::string, int);
        //GWNOutPort();    // NOT required to initialize <vector>
        //void post_message(std::string);  // moved to gwnblock_impl
     };

    class GWNInPort: public virtual GWNPort {
      public:
        GWNInPort(gwnblock_impl *, std::string, int);
        //GWNInPort();    // NOT required to initialize <vector>
    }; 
        




  } // namespace gwncppvgb
} // namespace gr

#endif /* INCLUDED_GWNCPPVGB_GWNBLOCK_IMPL_H */

