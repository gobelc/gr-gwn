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

#ifndef INCLUDED_GWNCPPVGB_GWNBLOCKC_IMPL_H
#define INCLUDED_GWNCPPVGB_GWNBLOCKC_IMPL_H

#include <gwncppvgb/gwnblockc.h>

/*  GWN inclusions */
#include <vector>
#include <gwncppvgb/gwnblockc_pdata.h>


namespace gr {
  namespace gwncppvgb {

    /*
     * Please consider some comments // and <text thus enclosed>
     * will be substituted by the gwn_modtool.sh script when
     * creating a new type of block. DO NOT ALTER, the script
     * needs those comments for correct substitution.
     */


    /* GWN gwnblockc, a template block */

    class gwnblockc_impl : public virtual gwnblockc
    {
    private:
      /* GWN ports, nested classes */
      class GWNPort
      {
        protected:
          bool d_debug;
        public:
          GWNPort();
          gwnblockc_impl * d_block;
          std::string d_port;
          int d_port_nr;
          std::string __str__();
      }; 
      class GWNOutPort: public virtual GWNPort { 
        public:
          GWNOutPort(gwnblockc_impl *, std::string, int);
       };
      class GWNInPort: public virtual GWNPort {
        public:
          GWNInPort(gwnblockc_impl *, std::string, int);
      }; 

      // GWN user arguments declaration

      gwnblockc_pdata * pdata_obj;

    public:
      gwnblockc_impl(<GWN user arguments list>);
      ~gwnblockc_impl();

      /* GWN attributes and functions */
      std::string d_name;
      int d_number_in, d_number_out, d_number_timers, d_number_timeouts;
      std::vector<GWNOutPort *> d_ports_out; 
      std::vector<GWNInPort *> d_ports_in;
      bool d_debug;
      void post_message(pmt::pmt_t, pmt::pmt_t);
      void handle_msg(pmt::pmt_t);
      void process_data(std::string);
      std::string __str__();

      // GNU Radio defaults 
      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
    };

  } // namespace gwncppvgb
} // namespace gr

#endif /* INCLUDED_GWNCPPVGB_GWNBLOCKC_IMPL_H */

