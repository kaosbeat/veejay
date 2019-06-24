```
 __   __   __     __    __     ______
/\ \ / /  /\ \   /\ "-./  \   /\  ___\   
\ \ \'/   \ \ \  \ \ \-./\ \  \ \___  \  
 \ \__|    \ \_\  \ \_\ \ \_\  \/\_____\ 
  \/_/      \/_/   \/_/  \/_/   \/_____/ 
```
VIMS is Veejay's IMS (Internal Message System)
=======================

[//]: # ( comment : BEGIN VIMS section DUPLICATE in /veejay-current/veejay-server/doc/HOWTO)
[//]: # ( WARNING : section numbering have to be adapted )

Veejay is server/client model and all control data is distributed via VIMS. Each (atomical) message consists of an _Action Identifier_ ( aka __selector__ ) 
and a list of zero or more _Arguments_ which can be used to control Video Clips, Video Streams, the Effect Chain and many other things.

VIMS allows events to be triggered through:

* SDL - Keyboard Event ([libsdl](https://en.wikipedia.org/wiki/Simple_DirectMedia_Layer))
* OSC - Synthesizers, computers, and other multimedia devices network protocol ([Open Sound Control](https://en.wikipedia.org/wiki/Open_Sound_Control))
* IMP - Veejay Internal Message Protocol

Along this documention we will review what messages you can send to veejay through using VIMS, Keyboard Event an OSC.

To quickly see documentation generated by veejay on VIMS, using Effects and OSC, use the command :

    $ veejay -u -n |less

If there is an error in the documentation, you have found a bug in veejay and should [report it](https://github.com/c0ntrol/veejay/issues) :)

After [installing](./Installation.md) `veejay-utils` package, you will have a commandline utility `sayVIMS` that we will discuss in this documentation.

Inside of veejay's source package you will find a `test/` directory containing various examples demonstrating how to load an ActionFile, how to use Perl for batch like video processing and how to attach message bundles to keyboard events.

Enough presentation, let's go deep in veejay messaging.


1.1 Message Format
==================

A message is described as:

    <Action Identifer> : <Argument List> ;

Example:

    080:;
    099:0 0;

<Action Identifier>  
The action identifier is a 3 digit number describing a Network Event  
The colon is used to indicate the start of the Argument List and must be given.

<Argument List>  
The Argument List is described by a `printf()` style formatted template
which describes the number and type of arguments to be used.

The semicolon must be given to indicate the end of this message

1.2 Bundled Messages
====================

A message bundle is a special message that contains an ordered list of at least 1 or more messages. Each message is executed from left to right (first in, first out) while parsing the bundle.   

You can dynamically assign keybindings to trigger a bundle in reloaded ( Menu -> Preferences -> VIMS Bundles )

There is an example Action File that a number of bundles with keybindings:
```
$ veejay -v /path/to/video.avi -F test/livecinema/action-file.xml
```

The bundles can be triggered by the keys SHIFT + [ q,w,e,r,t,y,u,i,o,p,a,s,d,f,g,h,j,k,l,z,x,c,v,b,n,m ]

Structure of bundled message
============================

Example:
```
5032|BUN:002{361:0 3 56 230 93 0;361:0 4 1 7;}|
5033|BUN:003{361:0 3 56 230 93 0;361:0 4 1 7;361:0 5 1 7;}|
5034|BUN:003{361:0 3 56 230 93 0;361:0 4 1 7;361:0 5 1 8;}|
```

A message bundle is described as:
```
   BUN: <Number of Messages> {
      <Action Idenfifier> : <Argument List> ;
      <Action Identifier> : <Argument List> ;
      ...
      }
    ;
```

The token 'BUN:' indicates the start of a messaage bundle, the first 3 digit numeric
value represents the total number of messages in the bundle. The '{' symbol indicates
the start of a message block and is ended with '};' or just '}'.

1.3 Format of an Action File/Attaching Keys to Bundles
======================================================
```
<501 - 599> | <message bundle> |
```
The contents of some action file can be :
```
516|BUN:001{355:;}|
```

The message bundle BUN sends '355' for clear effect chain.  
This message bundle is attached to action identifier 516.

A key is attached to this function trough using the Client UI (Reloaded) or by using dynamic keymapping.

DYNAMIC KEYMAPPING:
==================
```
"083:516 <sdl symbol> <modifier> <optional arguments>;"
```

The message bundle can be attached to a key, for example `SHIFT + A` by sending
```
083:516 97 3;
```
Which attaches bundle '516' to SDL key '97' using a modifier '3', which is SHIFT.

Modifiers    : 0 = none, 1 = alt , 2 = ctrl,  3 = shift  
SDL Keys     : see `SDL_keycode.h` (somewhere like `/usr/include/SDL2/`)

If the number 0 is used for an event number, a given key combination can be
unset (wiped) :
```
083:0 97 3;
```
Alternativly, you can bind keys to any action identifier.  
The complete list can be viewd by typing `veejay -u |less` or with `reloaded` in `Menu/Preferences/VIMS Bundle`.

```
083:20 97 0 4;
```
The example above sets key 'a' to 'change video speed to 4'

General description of VIMS messages
=====================================

Some reserved numbers:
```
    clip id      0  :   select currently playing clip
    clip id     -1  :   select highest clip number
    chain entry -1  :   select current chain entry
    stream id    0  :   select currently playing stream
    stream id   -1  :   select highest stream number
    key modifier    :   0 = normal, 1= alt , 2 = ctrl, 3 = shift
    frame       -1  :   use highest possible frame number (usually num video frames)
    playback mode   :   0 = clip, 1 = stream, 2 = plain
    data format     :   yv16 (yuv 4:2:2 raw) , mpeg4, divx, msmpeg4v3,
                        div3, dvvideo, dvsd, mjpeg, i420 and yv12 (yuv 4:2:0 raw)
    loop type       :   0 = play once, 1 = normal loop, 2 = pingpong (bounce) loop, 3 = random frame, 4 = Play once (no pause)
```
[//]: # ( comment : END VIMS section DUPLICATE in /veejay-current/veejay-server/doc/HOWTO)
[//]: # ( WARNING : section numbering have to be adapted )

What follows now is a general description of argument formatting and its ordering.
Note that `veejay -u` describe all VIMS arguments as well.
I wont put it into this document, since auto documentation work much better
(eliminating the need to update this documentation when things change).

In all __EditList__ commands, the arguments represent frame numbers (from 0 - max frames)

For example:
```
021:10 100; will copy frames 10-100 into a temporary buffer
020:100;    will insert the frames 10-100 from the temporary buffer on frame 100
```

For all __Clip__ commands, the first argument always represent the clip number except for 099
(create new clip) which takes 2 arguments ; starting and ending positions.
The arguments that may follow usually represent a number to describe either a property setting
(like speed, slow motion or looptype) and in other cases relative or real frame numbers.

Idem for __Streams__ commands.

In general, for __Chain__ commands the first argument is also the clip or stream number.
The second (or following arguments) usually represent the property setting or some value.

For example; 178 (fade in) takes 2 arguments. The first is to identify the clip number,
the second describes the duration (in frames) for the fade in.

181 (set effect with defaults) takes 3 arguments. Again, the first is to identify a clip or
stream, the second for the chain entry and the last for the effect number.
Idem for 182, but here starting from the 4th argument it takes preset values

2 sayVIMS, an utility to talk to veejay
=========================================

[//]: # ( comment : BEGIN sayVIMS section DUPLICATE in /veejay-current/veejay-server/doc/HOWTO)
[//]: # ( WARNING : section numbering have to be adapted )

***sayVIMS*** is a commandline utility distributed with the veejay package. It allows you to send short commands in interactive mode, single VIMS message or files containing VIMS messages to batch-process to veejay.
```
Usage: sayVIMS [options] [messages]
where options are:
 -p          Veejay port (3490)
 -g          Veejay groupname (224.0.0.31)
 -h          Veejay hostname (localhost)
 -m          Send single message
 -i          Interactive mode
 -f file     Read from (special) file
 -d          Dump status to stdout
 -b          Base64 encode binary data
 -v          Verbose
 -?          Print this help
```

In the following examples, lets say a veejay instance is running on host
`localhost` using port `3490` (veejay default values).

**Interactive Mode**
```
$ sayVIMS -i -h localhost -p 3490
```
In interactive mode, after a connection is establish with a veejay server,
a prompt wait you to enter VIMS commands (see previous chapter about the VIMS message format). Simply press `[ENTER]` to send it. 

```
$ sayVIMS -i
veejay sayVIMS 1.1.8
    type 'quit' or press CTRL-c to exit
    see 'veejay -u' for a list of commands
017:;
```
Here, the `017` tells veejay to go to sample starting position.

The connection remain open until you exit by typing `quit` or hit  `[Ctrl]-[c]`.

**Single VIMS message**

Also, you can send single VIMS format message.

For example, add the Pixelate effect on the Effect Chain of the current
playing stream or clip :
```
$ sayVIMS -h localhost -p 3490 -m "361:0 0 100 3;"
```

**Using files**

Last but not least, sayVIMS can parse files containing VIMS messages.

See the `veejay-server/test/examples` directory of the package for a list of perl
scripts that output a VIMS script.
```
$ sayVIMS -f advocate.vims -h localhost -p 3490
```

**Others examples**

Alternatively, you can start a secundary veejay and stream from peer to
peer (TCP) in uncompressed video:
```
$ veejay -d -p 5000
$ sayVIMS -h localhost -p 5000 -m "245:localhost 3490;"

(press 'F7' in veejay to display the stream, prob. stream 7)
```
Or for multicast (UDP):
```
$ veejay -V 224.0.0.50 -p 5000 -n -L movie1.avi
$ veejay -d
$ sayVIMS -h localhost -p 3490 -m "246:224.0.0.50 5000;"
$ veejay -d -p 4000
$ sayVIMS -h localhost -p 4000 -m "246:224.0.0.50 5000;"
```
Have a look on [4.5.3 network](./veejay-HOWTO.md#4.5.3) for more UDP multicasting.

[//]: # ( comment : END sayVIMS section DUPLICATE in /veejay-current/veejay-server/doc/HOWTO)
[//]: # ( WARNING : url have to be adapted )

3 OSC  - Open Sound Control
===================

The OpenSound Control WWW page is http://opensoundcontrol.org/

(quote from the website)

> OpenSound Control ("OSC") is a protocol for communication among computers, sound synthesizers
and other multimedia devices that is optimized for modern networking technology.

Veejay starts up an OSC server that listens on port number VJ_PORT + 2  (usually 3492). 
In the veejay/libOMC/send+dump you can compile a test application that sends OSC strings to veejay.
Bundled messages are handled automatically by libOMC.

Type `veejay -u |less` to see an overview of all actions, it includes OSC. The OSC messages
are mapped onto its respective VIMS Action Identifiers.


Examples:

* To create a new clip and play it:
```
/clip/new 100 200
/clip/select 0
```

* To record from a clip and auto play the recording after 10 seconds of PAL video:
```
/clip/record/start 250 1
```

* To add Effect 45 to the clip's Effect Chain
```
/clip/chain/entry/add 45
```

* To fade in the Effect Chain in 4 seconds
```
/clip/chain/fade_in 100
```

* To add Effect 45 on Entry 4 of clip 2's Effect Chain
```
/clip/chain/add 2 4 45
```

* To play newest clip
```
/clip/select
```

* To record from a clip and auto play the new clip after recording
```
/clip/record 100 1
```

Currently, OSC support in veejay is meant for triggering only.  
Some users have showed genuine interest in building user interfaces for Veejay using
this protocol. However, for such thing bi-directional communication is required
(i.e. current frame number, current playing clip, total number of clips, etc etc)

In veejay, VIMS provides a status port that can be read which will provide all kind
of status information but it is not mapped to OSC yet.

Also, in the veejay source package you will find a utility `mcastOSC` (which is 
not installed by default)

Build instructions (from veejay-server top source directory)
```
$ cd test/OSC
$ cd libOSC
$ make
$ cd ..
$ cd send+dump
$ make
```

Start veejay with -M or --multicast-osc , and use mcastOSC to control
all instances of veejay listening on the given multicast address.
(One tool to rule all).
 

SAVING/RESTORING Veejay states
===============================
Example configuration file (with most options)
```
<config>
  <run_settings>
    <port_num>3490</port_num>
<!- the port number veejay listens on ->
    <SDLwidth>352</SDLwidth>
    <SDLheight>288</SDLheight>
<!- SDL video window dimensions ->
    <audio>1</audio>
<!- Start with audio turned on ->
    <sync>1</sync>
<!- Try to keep in sync ->
    <timer>2</timer>
<!- Use system clock ->
    <output_fps>3</output_fps>
<!- Set a different output framerate (only affects playback) ->
    <Xgeom_x>0</Xgeom_x>
    <Xgeom_y>0</Xgeom_y>
<!- Use X geometry offset (from root window) ->
    <bezerk>1</bezerk>
<!- Bezerk is enabled by default ->
    <nocolor>0</nocolor>
<!- No colored console output ->
    <chrominance_level>1</chrominance_level>
<!- YUV 4:2:2 ->
    <output_width>352</output_width>
    <output_height>288</output_height>
<!- Output video dimensions (real width and height) ->
    <dummy_fps>0.000000</dummy_fps>
    <video_norm>0</video_norm>
    <dummy>0</dummy>
    <mcast_osc>0</mcast_osc>
<!- Dont use OSC multicast send/receive ->
    <mcast_vims>0</mcast_vims>
<!- Dont use VIMS multicast send/receive ->
    <output_scaler>0</output_scaler>
<!- Dont use the software output scaler (depends on output_widhth ->
<!- and output_height ) ->
  </run_settings>
</config>
```

Initially, you can setup veejay on the commandline and tell it to save
its settings in a configuration file.
```
veejay -z 1 -W 720 -H 576 /tmp/videofile.avi -p 5000
```
(in another terminal)
``` 
sayVIMS -h localhost -p 5000 -m "084:/tmp/config.tmp 1;"
```
In this file, not only the configuration is stored :
Bundled VIMS events, valid VIMS identifiers and Keymappings are
stored here.