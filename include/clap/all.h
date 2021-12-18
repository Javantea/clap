#pragma once

#include "clap.h"

#include "ext/audio-ports.h"
#include "ext/audio-ports-config.h"
#include "ext/gui.h"
#include "ext/gui-x11.h"
#include "ext/gui-win32.h"
#include "ext/gui-cocoa.h"
#include "ext/gui-free-standing.h"
#include "ext/log.h"
#include "ext/params.h"
#include "ext/render.h"
#include "ext/state.h"
#include "ext/latency.h"
#include "ext/thread-check.h"
#include "ext/timer-support.h"
#include "ext/fd-support.h"
#include "ext/note-name.h"
#include "ext/note-ports.h"
#include "ext/event-filter.h"
#include "ext/thread-pool.h"

#include "ext/draft/preset-load.h"
#include "ext/draft/quick-controls.h"
#include "ext/draft/track-info.h"
#include "ext/draft/tuning.h"
#include "ext/draft/file-reference.h"
#include "ext/draft/vst2-convert.h"
#include "ext/draft/vst3-convert.h"
#include "ext/draft/midi-mappings.h"

#include "converters/vst2-converter.h"
#include "converters/vst3-converter.h"