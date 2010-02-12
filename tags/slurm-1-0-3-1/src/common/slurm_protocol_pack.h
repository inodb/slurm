/****************************************************************************\
 *  slurm_protocol_pack.h - definitions for all pack and unpack functions
 *****************************************************************************
 *  Copyright (C) 2002 The Regents of the University of California.
 *  Produced at Lawrence Livermore National Laboratory (cf, DISCLAIMER).
 *  Written by Kevin Tew <tew1@llnl.gov>.
 *  UCRL-CODE-217948.
 *  
 *  This file is part of SLURM, a resource management program.
 *  For details, see <http://www.llnl.gov/linux/slurm/>.
 *  
 *  SLURM is free software; you can redistribute it and/or modify it under
 *  the terms of the GNU General Public License as published by the Free
 *  Software Foundation; either version 2 of the License, or (at your option)
 *  any later version.
 *  
 *  SLURM is distributed in the hope that it will be useful, but WITHOUT ANY
 *  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 *  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 *  details.
 *  
 *  You should have received a copy of the GNU General Public License along
 *  with SLURM; if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
\*****************************************************************************/

#ifndef _SLURM_PROTOCOL_PACK_H
#define _SLURM_PROTOCOL_PACK_H

#if HAVE_CONFIG_H
#  include "config.h"
#  if HAVE_INTTYPES_H
#    include <inttypes.h>
#  else
#    if HAVE_STDINT_H
#      include <stdint.h>
#    endif
#  endif  /* HAVE_INTTYPES_H */
#else   /* !HAVE_CONFIG_H */
#  include <inttypes.h>
#endif  /*  HAVE_CONFIG_H */

#include "src/common/pack.h"
#include "src/common/slurm_protocol_defs.h"

/****************************/
/* Message header functions */
/****************************/

/* pack_header
 * packs a slurm protocol header that proceeds every slurm message
 * IN header - the header structure to pack
 * IN/OUT buffer - destination of the pack, contains pointers that are
 *			automatically updated
 */
extern void pack_header ( header_t  * header , Buf buffer );

/* unpack_header
 * unpacks a slurm protocol header that proceeds every slurm message
 * OUT header - the header structure to unpack
 * IN/OUT buffer - source of the unpack data, contains pointers that are
 *			automatically updated
 * RET 0 or error code
 */
extern int unpack_header ( header_t * header , Buf buffer );


/**************************************************************************/
/* generic case statement Pack / Unpack methods for slurm protocol bodies */
/**************************************************************************/

/* pack_msg
 * packs a generic slurm protocol message body
 * IN msg - the body structure to pack (note: includes message type)
 * IN/OUT buffer - destination of the pack, contains pointers that are 
 *			automatically updated
 * RET 0 or error code
 */
extern int pack_msg ( slurm_msg_t const * msg , Buf buffer );

/* unpack_msg
 * unpacks a generic slurm protocol message body
 * OUT msg - the body structure to unpack (note: includes message type)
 * IN/OUT buffer - source of the unpack, contains pointers that are 
 *			automatically updated
 * RET 0 or error code
 */
extern int unpack_msg ( slurm_msg_t * msgi , Buf buffer );

/***************************************************************************/
/* specific case statement Pack / Unpack methods for slurm protocol bodies */
/***************************************************************************/

/* pack_job_credential
 * packs a slurm job credential
 * IN cred - pointer to the credential
 * IN/OUT buffer - destination of the pack, contains pointers that are 
 *			automatically updated
 */
/* void pack_job_credential ( slurm_job_credential_t* cred , Buf buffer ) ;*/

/* unpack_job_credential
 * unpacks a slurm job credential
 * OUT cred - pointer to the credential pointer
 * IN/OUT buffer - source of the unpack, contains pointers that are 
 *			automatically updated
 * RET 0 or error code
 */
/* int unpack_job_credential( slurm_job_credential_t** cred , Buf buffer ) ;*/

/* pack_job_step_info
 * packs a slurm job steps info
 * IN step - pointer to the job step info
 * IN/OUT buffer - destination of the pack, contains pointers that are 
 *			automatically updated
 */
void pack_job_step_info ( job_step_info_t* step, Buf buffer );

/* pack_job_step_info_members
 * pack selected fields of the description of a job into a buffer
 * IN job_id, step_id, user_id, start_time, partition, nodes - job info
 * IN/OUT buffer - destination of the pack, contains pointers that are 
 *			automatically updated
 */ 
void pack_job_step_info_members( uint32_t job_id, uint16_t step_id, 
		uint32_t user_id, uint32_t num_tasks, time_t start_time, 
		char *partition, char *nodes, char *name, char *network,
		Buf buffer );

#endif