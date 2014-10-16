
/*-
 *   BSD LICENSE
 *
 *   Copyright(c) 2010-2014 Netdp Corporation. All rights reserved.
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *     * Neither the name of Netdp Corporation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <netinet/in.h>
#include <termios.h>
#ifndef __linux__
  #ifdef __FreeBSD__
    #include <sys/socket.h>
  #else
    #include <net/socket.h>
  #endif
#endif

#include <cmdline_rdline.h>
#include <cmdline_parse.h>
#include <cmdline_parse_ipaddr.h>
#include <cmdline_parse_num.h>
#include <cmdline_parse_string.h>
#include <cmdline.h>
#include <cmdline_socket.h>

#include <rte_memory.h>
#include <rte_memzone.h>
#include <rte_tailq.h>
#include <rte_eal.h>
#include <rte_debug.h>
#include <rte_log.h>

#include "netdp_errno.h"
#include "netdp_socket_intf.h"


char netdpsock_flag = 0;

/**********************************************************************
*@description:
* 
*
*@parameters:
* [in]: 
* [in]: 
*
*@return values: 
*
**********************************************************************/
int netdpsock_init()
{
    int ret;
    int     param_num = 7;
    char *param[] = {"netdpsock",
                               "-c",
                               "1",
                               "-n",
                               "1",
                               "--socket-mem=1",
                               "--proc-type=secondary",
                               NULL};


    if(netdpsock_flag != 0)
        return NETDP_EOK;
    
    rte_set_log_level(RTE_LOG_ERR);
    ret = rte_eal_init(param_num, param);
    if (ret < 0)
        return ret;

    ret = netdpsock_ring_init();
    if(ret != 0)
        return ret;
    
}



int netdpsock_socket(int domain, int type, int protocol)
{

}

