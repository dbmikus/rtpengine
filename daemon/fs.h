#ifndef __FS_H__
#define __FS_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include "call.h"

/**
 * Initialize RTP Engine filesystem settings and structure.
 * Check for or create the RTP Engine spool directory.
 */
void fs_init(char *spooldir);

/**
 * Create a call metadata file in a temporary location.
 * Attaches the filepath and the file pointer to the call struct.
 */
str *setup_meta_file(struct call *call);

/**
 * Writes metadata to metafile, closes file, and renames it to finished location.
 * Returns non-zero for failure.
 */
int meta_file_finish(struct call *call);

/**
 * Generate a random PCAP filepath to write recorded RTP stream.
 */
str *setup_recording_file(struct call *call, struct call_monologue *monologue);

/**
 * Write out a PCAP packet with payload string.
 * A fair amount extraneous of packet data is spoofed.
 */
void stream_pcap_dump(pcap_dumper_t *pdumper, str *s);

#endif
