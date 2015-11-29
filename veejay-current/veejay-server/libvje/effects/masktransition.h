/*
 * Linux VeeJay
 *
 * Copyright(C)2002-2015 Niels Elburg <nwelburg@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License , or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307 , USA.
 */

#ifndef MASKTRANSITION_H
#define MASKTRANSITION_H
#include <libvje/vje.h>
#include <sys/types.h>
#include <stdint.h>

void masktransition_apply( VJFrame *frame, VJFrame *frame2, int width,int height, int index, int duration);
void	alpha_transition_apply( VJFrame *frame, uint8_t *B[4], int time_index );
vj_effect *masktransition_init(int w, int h);
#endif
