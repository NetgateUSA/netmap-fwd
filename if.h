/*-
 * Copyright (c) 2015, Luiz Souza <loos@freebsd.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <net/if.h>
#include <net/if_dl.h>
#include <net/netmap.h>
#include <net/netmap_user.h>

struct nm_if {
	STAILQ_ENTRY(nm_if)	nm_if_;
	char			nm_if_name[IF_NAMESIZE];
	int			nm_if_fd;
	int			nm_if_flags;
	int			nm_if_metric;
	int			nm_if_mtu;
	int			nm_if_naddrs;
	int			nm_if_txsync;
	size_t			nm_if_memsize;
	struct event		*nm_if_ev_read;
	struct sockaddr_dl	nm_if_dl;	/* lladdr */
	struct netmap_if	*nm_if_ifp;
	uint32_t		nm_if_rx_rings;
	uint32_t		nm_if_tx_rings;
	void			*nm_if_mem;
};

void if_init(void);
int if_open(const char *);
int if_netmap_txsync(void);