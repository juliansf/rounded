/**CHeaderFile*****************************************************************

  FileName    [HrcDumperDebug.h]

  PackageName [hrc.dumper]

  Synopsis    [Public interface of class 'HrcDumperDebug']

  Description []

  SeeAlso     [HrcDumperDebug.c]

  Author      [Roberto Cavada]

  Copyright   [
  This file is part of the ``hrc.dumper'' package of NuSMV version 2. 
  Copyright (C) 2011 by FBK-irst. 

  NuSMV version 2 is free software; you can redistribute it and/or 
  modify it under the terms of the GNU Lesser General Public 
  License as published by the Free Software Foundation; either 
  version 2 of the License, or (at your option) any later version.

  NuSMV version 2 is distributed in the hope that it will be useful, 
  but WITHOUT ANY WARRANTY; without even the implied warranty of 
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU 
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public 
  License along with this library; if not, write to the Free Software 
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA.

  For more information on NuSMV see <http://nusmv.fbk.eu>
  or email to <nusmv-users@fbk.eu>.
  Please report bugs to <nusmv-users@fbk.eu>.

  To contact the NuSMV development board, email to <nusmv@fbk.eu>. ]

  Revision    [$Id: $]

******************************************************************************/


#ifndef __HRC_DUMPER_DEBUG_H__
#define __HRC_DUMPER_DEBUG_H__


#include "HrcDumper.h" /* fix this */ 
#include "utils/utils.h" 


/**Type***********************************************************************

  Synopsis    [Definition of the public accessor for class HrcDumperDebug]

  Description []

******************************************************************************/
typedef struct HrcDumperDebug_TAG*  HrcDumperDebug_ptr;


/**Macros**********************************************************************

  Synopsis    [To cast and check instances of class HrcDumperDebug]

  Description [These macros must be used respectively to cast and to check
  instances of class HrcDumperDebug]

******************************************************************************/
#define HRC_DUMPER_DEBUG(self) \
         ((HrcDumperDebug_ptr) self)

#define HRC_DUMPER_DEBUG_CHECK_INSTANCE(self) \
         (nusmv_assert(HRC_DUMPER_DEBUG(self) != HRC_DUMPER_DEBUG(NULL)))



/**AutomaticStart*************************************************************/

/*---------------------------------------------------------------------------*/
/* Function prototypes                                                       */
/*---------------------------------------------------------------------------*/

EXTERN HrcDumperDebug_ptr HrcDumperDebug_create ARGS((FILE* fout));


/**AutomaticEnd***************************************************************/



#endif /* __HRC_DUMPER_DEBUG_H__ */
