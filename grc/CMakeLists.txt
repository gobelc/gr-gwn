# Copyright 2011 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# GNU Radio is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# GNU Radio is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Radio; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
install(FILES
    gwncppvgb_message_timer_example.xml
    gwncppvgb_fsm_test.xml
    gwncppvgb_fsmblk.xml
    gwncppvgb_gwnmsg_source.xml
    gwncppvgb_gwnmsg_sink.xml
    gwncppvgb_virtual_channel.xml
    gwncppvgb_stop_wait_ack.xml
    gwncppvgb_arq_sender.xml
    gwncppvgb_arq_sender_fsm.xml DESTINATION share/gnuradio/grc/blocks
)
