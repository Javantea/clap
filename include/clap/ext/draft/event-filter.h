#pragma once

#include "../../plugin.h"

static CLAP_CONSTEXPR const char CLAP_EXT_EVENT_FILTER[] = "clap.event-filter/draft";

#ifdef __cplusplus
extern "C" {
#endif

// This extension lets the host know which event types the plugin is interested
// in. The purpose is to reduce the number of events in the stream and not to
// infer plugin's capabilities from it.
//
// This extension is currently in draft because we are not sure which aproach is best: whitelist vs
// blacklist and how much impact it has over the number of events. When a plugin supports polyphonic
// modulations, then the event queue can grow massively and this extension would then become
// irrelevant.
//
// The host will cache the set of accepted events before activating the plugin.
// The set of accepted events can't change while the plugin is active.
//
// If this extension is not provided by the plugin, then all events are accepted.
//
// If CLAP_EVENT_TRANSPORT is not accepted, then clap_process.transport may be null.
typedef struct clap_plugin_event_filter {
   // Returns true if the plugin is interested in the given event type.
   // [main-thread]
   bool (*accepts)(const clap_plugin_t *plugin, uint16_t space_id, uint16_t event_type);
} clap_plugin_event_filter_t;

typedef struct clap_host_event_filter {
   // Informs the host that the set of accepted event type changed.
   // This requires the plugin to be deactivated.
   // [main-thread]
   void (*changed)(const clap_host_t *host);
} clap_host_event_filter_t;

#ifdef __cplusplus
}
#endif