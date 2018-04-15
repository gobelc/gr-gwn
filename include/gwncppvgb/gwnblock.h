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


#ifndef INCLUDED_GWNCPPVGB_GWNBLOCK_H
#define INCLUDED_GWNCPPVGB_GWNBLOCK_H

#include <gwncppvgb/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace gwncppvgb {

    /*!
     * \brief <+description of block+>
     * \ingroup gwncppvgb
     *
     */
    class GWNCPPVGB_API gwnblock : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<gwnblock> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of gwncppvgb::gwnblock.
       *
       * To avoid accidental use of raw pointers, gwncppvgb::gwnblock's
       * constructor is in a private implementation
       * class. gwncppvgb::gwnblock::make is the public interface for
       * creating new instances.
       */
      static sptr make(std::string name, int number_in, int number_out, int number_timers, int number_timeouts);

      std::string my__str__();


    };

  } // namespace gwncppvgb
} // namespace gr

#endif /* INCLUDED_GWNCPPVGB_GWNBLOCK_H */
