/**CHeaderFile*****************************************************************

  FileName    [transInt.h]

  PackageName [trans]

  Synopsis    [ The internal header file of <tt>trans</tt> package.]

  Description []

  SeeAlso     []

  Author      [Roberto Cavada]

  Copyright   [
  This file is part of the ``trans'' package of NuSMV version 2. 
  Copyright (C) 2003 by FBK-irst. 

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

  Revision    [$Id: transInt.h,v 1.1.2.6.4.2 2005-11-16 12:04:44 nusmv Exp $]

******************************************************************************/

#ifndef __TRANS_INT_H__
#define __TRANS_INT_H__

#include "utils/utils.h" /* for EXTERN and ARGS */
#include "opt/opt.h"   /* for options_ptr */


/*---------------------------------------------------------------------------*/
/* Constant declarations                                                     */
/*---------------------------------------------------------------------------*/
#define TRANS_TYPE_MONOLITHIC_STRING  "Monolithic" 
#define TRANS_TYPE_THRESHOLD_STRING   "Threshold" 
#define TRANS_TYPE_IWLS95_STRING      "Iwls95CP" 

/*---------------------------------------------------------------------------*/
/* Type declarations                                                         */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* Structure declarations                                                    */
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
/* Variable declarations                                                     */
/*---------------------------------------------------------------------------*/

EXTERN FILE* nusmv_stderr;
EXTERN FILE* nusmv_stdout;


#endif /* __TRANS_INT_H__ */
