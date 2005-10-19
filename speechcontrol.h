/*
    This file is part of Kismet

    Kismet is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Kismet is distributed in the hope that it will be useful,
      but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Kismet; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "config.h"

#ifndef __SPEECHCONTROL_H__
#define __SPEECHCONTROL_H__

#include "globalregistry.h"
#include "pollable.h"
#include "ipc_remote.h"

#define SPEECH_ENCODING_NORMAL   0
#define SPEECH_ENCODING_NATO     1
#define SPEECH_ENCODING_SPELL    2

extern char speech_alphabet[2][36][12];

class SpeechControl {
public:
    SpeechControl();
    SpeechControl(GlobalRegistry *in_globalreg);
    virtual ~SpeechControl();

    // Kill
    void Shutdown();
   
    // Send something to the speech pipe
    int SayText(string in_text);

    // Encode to nato, etc
    string EncodeSpeechString(string in_str);

	// Fetch the player command
	char *FetchPlayer() { return player; }

protected:
	int SpawnChildProcess();

    GlobalRegistry *globalreg;

	IPCRemote *speech_remote;

	uint32_t speech_ipc_id;
 
	int speech_enable;

    char errstr[STATUS_MAX];

    char *player;

    int speech_encoding;
    char *festival;
    string speech_sentence_encrypted, speech_sentence_unencrypted;
};

#endif

