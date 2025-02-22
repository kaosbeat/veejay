/* 
 * Linux VeeJay
 *
 * Copyright(C)2002 Niels Elburg <nwelburg@gmail.com>
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

#include "common.h"
#include <veejaycore/vjmem.h>
#include "pixelate.h"

vj_effect *pixelate_init(int width, int height)
{
	vj_effect *ve = (vj_effect *) vj_calloc(sizeof(vj_effect));
	ve->num_params = 1;
	ve->defaults = (int *) vj_calloc(sizeof(int) * ve->num_params);	/* default values */
	ve->limits[0] = (int *) vj_calloc(sizeof(int) * ve->num_params);	/* min */
	ve->limits[1] = (int *) vj_calloc(sizeof(int) * ve->num_params);	/* max */
	ve->limits[0][0] = 1;
	ve->limits[1][0] = 2048;
	ve->defaults[0] = 8;
	ve->description = "Pixelate";
	ve->sub_format = -1;
	ve->extra_frame = 0;
	ve->has_user =0;
	ve->parallel = 1;
	ve->param_description = vje_build_param_list( ve->num_params, "Pixels");
	return ve;
}

void pixelate_apply( void *ptr, VJFrame *frame, int *args )
{
	unsigned int i,j ;
	const int len = frame->len;
	const unsigned int v = args[0];
	const int uv_len = (frame->ssm ? len : frame->uv_len);
	unsigned int u_v = v >> (frame->ssm ? frame->shift_h: 1 );
	if( u_v == 0 )
		u_v = 1;
	
	uint8_t *Y = frame->data[0];
	uint8_t *Cb= frame->data[1];
	uint8_t *Cr= frame->data[2];

	for (i = 0; i < len; i+=v) {
		for(j=0; j < v; j++)
		{
			Y[i+j] = Y[i];
		}
	}

	for (i = 0; i < uv_len; i+=u_v) {
		for(j=0; j < u_v; j++)
		{
			Cb[i+j] = Cb[i];
			Cr[i+j] = Cr[i];
		}
	}
}

