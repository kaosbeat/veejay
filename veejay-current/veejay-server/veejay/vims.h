/* veejay - Linux VeeJay
 * 	     (C) 2002-2008 Niels Elburg <nwelburg@gmail.com> 
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#ifndef VIMS_H
#define VIMS_H

enum {
	VIMS_BUNDLE_START	=	500,
	VIMS_BUNDLE_END		=	599,	
	VIMS_MAX		=	602,
};

enum {
	VIMS_FXLIST_INC					=	1,
	VIMS_FXLIST_DEC					=	2,
	VIMS_FXLIST_ADD					=	3,	
	VIMS_PRINT_INFO					=	4,
	VIMS_PREVIEW_BW					=	8,
	VIMS_VIEWPORT					=	9,		
	VIMS_FRONTBACK					=	6,
	VIMS_PROJECTION					=	7,
	VIMS_COMPOSITE					=	47,
	VIMS_RENDER_DEPTH				=	48,
	VIMS_FEEDBACK					= 	49,
	VIMS_MACRO						=	33,
	VIMS_MACRO_SELECT				=	34,
	VIMS_CONTINUOUS_PLAY			=	35,			//FIXME delete this event
	VIMS_RECVIEWPORT				=	90,
	VIMS_VIDEO_INFORMATION			=	400,
	VIMS_PROMOTION					=	444, /* obsolete */
	VIMS_EFFECT_LIST				=	401,
	VIMS_EDITLIST_LIST				=	402,
	VIMS_BUNDLE_LIST				=	403,
	VIMS_STREAM_LIST				=	405,
	VIMS_STREAM_DEVICES				=	406,
	VIMS_SAMPLE_HISTORY_LIST		=	407,
	VIMS_SAMPLE_LIST				=	408,
	VIMS_STREAM_GET_V4L				=	409,
	VIMS_CHAIN_GET_ENTRY			=	410,
	VIMS_VIMS_LIST					=	411,
	VIMS_SAMPLE_INFO				=	413,
	VIMS_SAMPLE_OPTIONS				=	414,
	VIMS_DEVICE_LIST				=	415,
	VIMS_FONT_LIST					=	416,
	VIMS_SRT_LIST					=	417,
	VIMS_SRT_INFO					=	418,
	VIMS_TRACK_LIST					=	5,
	VIMS_SEQUENCE_LIST				=	419,
	VIMS_KEYLIST					=	420,
	VIMS_WORKINGDIR					=	421,
	VIMS_SAMPLE_STACK				=	422,
	VIMS_GET_IMAGE					=	423,
	VIMS_GET_SHM_EXT				=	424,
	VIMS_GET_SHM					=  	425,
	VIMS_GET_SPLIT_IMAGE			=	426,
	VIMS_GET_SAMPLE_IMAGE			=	427,
	VIMS_GET_STREAM_ARGS			=	428,
	VIMS_CHAIN_GET_PARAMETERS		=	435,
	VIMS_GET_GENERATORS			=	436,
	VIMS_GET_FEEDBACK			=	437,
	VIMS_SET_VOLUME					=	300,
	VIMS_FULLSCREEN					=	301,
	VIMS_SUSPEND					=	254,
	VIMS_QUIT						=	600,
	VIMS_CLOSE						=	601,
	VIMS_LOAD_PLUGIN				=	310,
	VIMS_UNLOAD_PLUGIN				=	311,
	VIMS_CMD_PLUGIN					=	312,
	VIMS_RECORD_DATAFORMAT			=	302,
	VIMS_SET_PLAIN_MODE				= 	303,
	VIMS_INIT_GUI_SCREEN			=	304,
	VIMS_SWITCH_SAMPLE_STREAM		=	305,
	VIMS_AUDIO_ENABLE				=	306,
	VIMS_AUDIO_DISABLE				=	307,
	VIMS_SELECT_BANK				=	308,
	VIMS_SELECT_ID					=	309,
	VIMS_SAMPLE_RAND_START			=	315,
	VIMS_SAMPLE_RAND_STOP			=	316,
	VIMS_REC_AUTO_START				=	320,	
	VIMS_REC_STOP					=	321,
	VIMS_REC_START					=	322,
	VIMS_EFFECT_SET_BG				=	339,
	VIMS_SAMPLE_MODE				=	323,
	VIMS_BEZERK						=	324,
	VIMS_DEBUG_LEVEL				=	325,
	VIMS_RESIZE_SDL_SCREEN			=	326,
	VIMS_SET_PLAY_MODE				=	327,
	VIMS_SET_MODE_AND_GO			=	328,
	VIMS_RGB_PARAMETER_TYPE			=	329,
	VIMS_SCREENSHOT					=	330,
	VIMS_NO_CACHING					=	331,
	VIMS_RGB24_IMAGE					=	333,
	VIMS_CALI_IMAGE					=	332,
	VIMS_SYNC_CORRECTION			=	334,
	VIMS_FRAMERATE					=	335,
	VIMS_SUB_RENDER					=	336,
	VIMS_ALPHA_COMPOSITE			=	337,
	VIMS_RESUME_ID				=	338,
	VIMS_VIDEO_PLAY_FORWARD			=	10,
	VIMS_VIDEO_PLAY_BACKWARD		=	11,
	VIMS_VIDEO_PLAY_STOP			=	12,
	VIMS_VIDEO_SKIP_FRAME			=	13,
	VIMS_VIDEO_PREV_FRAME			=	14,
	VIMS_VIDEO_SKIP_SECOND			=	15,
	VIMS_VIDEO_PREV_SECOND			=	16,
	VIMS_VIDEO_GOTO_START			=	17,
	VIMS_VIDEO_GOTO_END				=	18,
	VIMS_VIDEO_SET_FRAME			=	19,
	VIMS_VIDEO_SET_SPEED			=	20,
	VIMS_VIDEO_SET_SLOW				=	21,
	VIMS_VIDEO_MCAST_START			=	22,
	VIMS_VIDEO_MCAST_STOP			=	23,
	VIMS_VIDEO_SET_SPEEDK			=	24,		
	VIMS_VIDEO_PLAY_STOP_ALL		=	26,
	VIMS_EDITLIST_PASTE_AT			=	50,
	VIMS_SPLIT_CONNECT_SHM			=	60,
	VIMS_SHM_WRITER					= 	25, 
	VIMS_EDITLIST_COPY				=	51,
	VIMS_EDITLIST_DEL				=	52,
	VIMS_EDITLIST_CROP				=	53,
	VIMS_EDITLIST_CUT				=	54,
	VIMS_EDITLIST_ADD				=	55,
	VIMS_EDITLIST_ADD_SAMPLE		=	56,
	VIMS_EDITLIST_SAVE				=	58,
	VIMS_EDITLIST_LOAD				=	59,
	VIMS_OFFLINE_SAMPLES			=	70,
	VIMS_OFFLINE_TAGS				=	71,
	VIMS_OFFLINE_PLAYMODE			=	72,
	VIMS_BUNDLE						=	80,
	VIMS_BUNDLE_DEL					=	81,
	VIMS_BUNDLE_ADD					=	82,
	VIMS_BUNDLE_ATTACH_KEY			=	83,
	VIMS_BUNDLE_FILE				=	84,
	VIMS_BUNDLE_SAVE				=	85,
	VIMS_BUNDLE_CAPTURE				=	86,
	VIMS_SET_SAMPLE_START			=	150,
	VIMS_SET_SAMPLE_END				=	151,
	VIMS_SAMPLE_KF_CLEAR			=   152,
	VIMS_SAMPLE_NEW					=	100,
	VIMS_SAMPLE_SELECT				=	101,
	VIMS_SAMPLE_DEL					=	120,
	VIMS_SAMPLE_SET_LOOPTYPE		=	102,
	VIMS_SAMPLE_SET_DESCRIPTION		=	103,
	VIMS_SAMPLE_SET_SPEED			=	104,
	VIMS_SAMPLE_SET_START			=	105,
	VIMS_SAMPLE_SET_END				=	106,
	VIMS_SAMPLE_SET_DUP				=	107,
	VIMS_SAMPLE_SET_MARKER_START	=	108,
	VIMS_SAMPLE_SET_MARKER_END		= 	109,
	VIMS_SAMPLE_SET_MARKER			=	110,
	VIMS_SAMPLE_SKIP_FRAME			=	114,
	VIMS_SAMPLE_CLEAR_MARKER		=	111,
	VIMS_SAMPLE_LOAD_SAMPLELIST		=	125,
	VIMS_SAMPLE_SAVE_SAMPLELIST		=	126,
	VIMS_SAMPLE_DEL_ALL				=	121,
	VIMS_SAMPLE_COPY				=	127,
	VIMS_SAMPLE_SET_POSITION		=	128,
	VIMS_SAMPLE_REC_START			=	130,
	VIMS_SAMPLE_REC_STOP			=	131,
	VIMS_SAMPLE_CHAIN_ENABLE		=	112,
	VIMS_SAMPLE_CHAIN_DISABLE		=	113,
	VIMS_SAMPLE_KF_STATUS_PARAM		=	142,
	VIMS_SAMPLE_UPDATE				=	143,
	VIMS_SAMPLE_TOGGLE_LOOP			=	144,
	VIMS_SAMPLE_TOGGLE_RAND_LOOP	=	154,
	VIMS_SAMPLE_KF_STATUS			=	145,
	VIMS_SAMPLE_KF_GET				=	146,
	VIMS_SAMPLE_KF_RESET			=	147,
	VIMS_SAMPLE_HOLD_FRAME			=	148,
	VIMS_SAMPLE_NEXT				=	149,
	VIMS_SAMPLE_MIX_SET_SPEED			=	153,
	VIMS_SAMPLE_MIX_SET_DUP				=	156,
	VIMS_STREAM_COLOR				=	202,
	VIMS_STREAM_SELECT				=	201,
	VIMS_STREAM_ACTIVATE			=	205,
	VIMS_STREAM_DEACTIVATE			=	206,
	VIMS_STREAM_DELETE				=	220,
	VIMS_STREAM_NEW_AVFORMAT			=	239,
	VIMS_STREAM_NEW_V4L				=	240,
	VIMS_STREAM_NEW_DV1394			=	241,
	VIMS_STREAM_NEW_COLOR			=	242,
	VIMS_STREAM_NEW_Y4M				=	243,
	VIMS_STREAM_NEW_CALI			=	244,
	VIMS_V4L_BLACKFRAME				=	248,
	VIMS_V4L_CALI					=	249,
	VIMS_STREAM_NEW_UNICAST			=	245,
	VIMS_STREAM_NEW_MCAST			=	246,
	VIMS_STREAM_NEW_PICTURE			=	247,
	VIMS_STREAM_NEW_GENERATOR		=	250,
	VIMS_STREAM_NEW_SHARED			=	251,
	VIMS_STREAM_NEW_CLONE			=	252,
	VIMS_STREAM_OFFLINE_REC_START	=	228,
	VIMS_STREAM_OFFLINE_REC_STOP	=	229,
	VIMS_STREAM_REC_START			=	230,
	VIMS_STREAM_REC_STOP			=	231,
	VIMS_STREAM_CHAIN_ENABLE		=	212,
	VIMS_STREAM_CHAIN_DISABLE		=	213,
	VIMS_STREAM_SET_DESCRIPTION		=	203,
	VIMS_STREAM_SET_BRIGHTNESS		=	207,
	VIMS_STREAM_SET_CONTRAST		=	208,
	VIMS_STREAM_SET_HUE				=	209,
	VIMS_STREAM_SET_COLOR			=	210,
	VIMS_STREAM_SET_WHITE			=	211,
	VIMS_STREAM_SET_SATURATION		=	215,	
	VIMS_STREAM_SET_LENGTH			=	216,
	VIMS_STREAM_SET_V4LCTRL			=	217,	
	VIMS_STREAM_SET_ARG				=	219,
	VIMS_SEQUENCE_STATUS			=	340,
	VIMS_SEQUENCE_ADD				=	341,
	VIMS_SEQUENCE_DEL				=	342,
	VIMS_PROJ_INC					=	160,
	VIMS_PROJ_DEC					=	161,
	VIMS_PROJ_SET_POINT				=	162,
	VIMS_PROJ_GET_POINT				=	163,
	VIMS_PROJ_STACK					=	164,
	VIMS_PROJ_TOGGLE				=	165,
	VIMS_CHAIN_ENTRY_SET_NARG_VAL	=	349,
	VIMS_CHAIN_ENTRY_CHANNEL_INC	=	350,
	VIMS_CHAIN_ENTRY_CHANNEL_DEC	=	351,
	VIMS_CHAIN_TOGGLE_ALL			=	352,
	VIMS_CHAIN_ENABLE				=	353,
	VIMS_CHAIN_DISABLE				=	354,
	VIMS_CHAIN_CLEAR				=	355,
	VIMS_CHAIN_FADE_IN				=	356,
	VIMS_CHAIN_FADE_OUT				=	357,
	VIMS_CHAIN_LIST					=	358,
	VIMS_CHAIN_SET_ENTRY			=	359,
	VIMS_CHAIN_ENTRY_SET_EFFECT		=	360,
	VIMS_CHAIN_ENTRY_SET_PRESET		=	361,
	VIMS_CHAIN_ENTRY_SET_ARG_VAL	=	362,
	VIMS_CHAIN_ENTRY_SET_VIDEO_ON	=	363,
	VIMS_CHAIN_ENTRY_SET_VIDEO_OFF	=	364,
	VIMS_CHAIN_ENTRY_SET_DEFAULTS	=	365,
	VIMS_CHAIN_ENTRY_SET_CHANNEL	=	366,
	VIMS_CHAIN_ENTRY_SET_SOURCE		=	367,
	VIMS_CHAIN_ENTRY_SET_SOURCE_CHANNEL=368,
	VIMS_CHAIN_ENTRY_CLEAR			=	369,
	VIMS_CHAIN_MANUAL_FADE			=	370,
	VIMS_CHAIN_ENTRY_DOWN			=	371,
	VIMS_CHAIN_ENTRY_UP				=	372,
	VIMS_CHAIN_ENTRY_SOURCE_TOGGLE	=	373,
	VIMS_CHAIN_ENTRY_INC_ARG		=	374,
	VIMS_CHAIN_ENTRY_DEC_ARG		=	375,
	VIMS_CHAIN_TOGGLE				=	376,
	VIMS_CHAIN_ENTRY_SET_STATE		=	377,
	VIMS_ENTRY_CHANNEL_UP			=	378,
	VIMS_ENTRY_CHANNEL_DOWN			=	379,
	VIMS_ENTRY_VIDEO_TOGGLE			=	380,
	VIMS_ENTRY_SOURCE_TOGGLE		=	381,
	VIMS_CHAIN_FOLLOW_FADE			=	382,
	VIMS_CHAIN_FADE_ENTRY			=	383,
	VIMS_CHAIN_FADE_METHOD			=	384,
	VIMS_CHAIN_FADE_ALPHA			=	385,
	VIMS_OSL						=	387,
	VIMS_OSD_EXTRA					=	388,
	VIMS_COPYRIGHT					=	389,
	VIMS_FONT_POS					=	390,
	VIMS_FONT_COL					=	391,
	VIMS_FONT_SIZE_FONT				=	392,
	VIMS_SRT_ADD					=	393,
	VIMS_SRT_DEL					=	394,
	VIMS_SRT_UPDATE					=	395,
	VIMS_SRT_SAVE					=	396,
	VIMS_SRT_LOAD					=	397,
	VIMS_SRT_SELECT					=	398,
	VIMS_OSD						=	399,
	VIMS_OUTPUT_Y4M_START			=	40,
	VIMS_OUTPUT_Y4M_STOP			=	41,
	VIMS_GET_FRAME					=	42,
	VIMS_VLOOPBACK_START			=	45,
	VIMS_VLOOPBACK_STOP				=	46,
};

#define VIMS_CHAIN_LIST_ENTRY_FORMAT "%02d%03d%1d%1d%1d%1d%03d%1d"
#define VIMS_CHAIN_LIST_ENTRY_LENGTH (2+3+1+1+1+1+3+1) // String length of entry format
#define VIMS_CHAIN_LIST_ENTRY_VALUES 8 // Number of values of the message

enum {
    VJ_PLAYBACK_MODE_PLAIN = 2,
    VJ_PLAYBACK_MODE_SAMPLE = 0,
    VJ_PLAYBACK_MODE_PATTERN = 3,
    VJ_PLAYBACK_MODE_TAG = 1,
    VJ_PLAYBACK_MODE_MEM = 4,
};

enum {
    VJ_MAX_V4L_DEVICES = 2,
    VJ_MAX_IN_STREAMS = 4,
    VJ_MAX_OUT_STREAMS = 1,
    VJ_MAX_VLOOPBACK_PIPES = 8,
};

/* request messages, global */
#define MAX_SEQUENCES		100
#define MAX_SPEED		32
#define SAMPLE_MAX_EFFECTS 	20
#define PATTERN_MAX_TRACKS	3
#define CELL_LENGTH		30
#define ROW_SIZE		(PATTERN_MAX_TRACKS * CELL_LENGTH)
#define PATTERN_DEFAULT_LENGTH  (25*60)
#define EDIT_CUT		101
#define EDIT_PASTE_AT		102
#define EDIT_COPY		103
#define EDIT_CROP		104
#define EDIT_DEL		105
#define MESSAGE_SIZE	1024	
#define EL_MIN_BUF		(65535 * 4)
#define XMLTAG_BUNDLE_FILE  "ACTIONFILE"
#define XMLTAG_EVENT_AS_KEY "BUNDLE"
#define SOCKETFRAMELEN		(1024*4096)
#define FMT_420 0
#define FMT_420F 2
#define FMT_422 1
#define FMT_422F 3
#define FMT_444 4
#define VEEJAY_PORT_CMD 0
#define VEEJAY_PORT_STA 1
#define VEEJAY_PORT_DAT 3
#define VEEJAY_PORT_MAT 2
#define VEEJAY_PORT_OSC 6

#define FMT_RGB24	2
#define FMT_RGB32	1

#define MAX_EDIT_LIST_FILES 4096

#define V_STATUS 1
#define V_CMD 0

enum
{
	VJ_CMD_PORT=0,
	VJ_STA_PORT=1,
	VJ_CMD_MCAST=3,
	VJ_CMD_MCAST_IN=4,
	VJ_MSG_PORT=5,
	VJ_CMD_OSC=2,
};


#endif
