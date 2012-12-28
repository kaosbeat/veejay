/* 
 * Linux VeeJay
 *
 * Copyright(C)2002-2012 Niels Elburg <elburg@hio.hen.nl>
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

#ifndef VJTASK_H
#define VJTASK_H
typedef	void	*(*performer_job_routine)(void *);

typedef struct
{
	uint8_t *input[4];
	uint8_t *output[4];
	int	strides[4];
	int	out_strides[4];
	uint8_t *temp[4];
	int	iparams[12];
	float fparam;
	int   iparam;
	void	*priv;
	void   *ptr;
	int   width;
	int   height;
	int   subwid;
	int   subhei;
	int   shiftv;
	int   shifth;
	int	sampling;
	int	ssm;
	int	uv_width;
	int	uv_height;
	int	jobnum;
	int	overlap;
	uint8_t *overlaprow;
} vj_task_arg_t;

void	vj_task_init();

int	vj_task_run(uint8_t **buf1, uint8_t **buf2, uint8_t **buf3, int *strides,int n_planes, performer_job_routine func );


void	*vj_task_alloc_internal_buf( unsigned int w );
void	vj_task_set_float( float f );
void	vj_task_set_int( int i );
void	vj_task_set_wid( int w );
void	vj_task_set_hei( int h );
void	vj_task_set_shift( int h, int v );
void	vj_task_set_ptr( void *ptr );
void	vj_task_set_to_frame( VJFrame *frame, int pos, int job );
void	vj_task_set_from_frame( VJFrame *frame );
void	vj_task_set_from_args( int len, int uv_len );
void	vj_task_set_param( int v, int idx );
void	vj_task_free_internal_buf();
void	*vj_task_get_internal_buf();
int	task_start(int max_workers);
void	task_stop(int max_workers);
void	task_init();
int	task_num_cpus();

void	performer_job( int job_num );

int	num_threaded_tasks();

#endif
