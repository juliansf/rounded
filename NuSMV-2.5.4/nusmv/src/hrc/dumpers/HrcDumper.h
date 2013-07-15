/**CHeaderFile*****************************************************************

  FileName    [HrcDumper.h]

  PackageName [hrc.dumpers]

  Synopsis    [Public interface of class 'HrcDumper']

  Description []

  SeeAlso     [HrcDumper.c]

  Author      [Roberto Cavada]

  Copyright   [
  This file is part of the ``hrc.dumpers'' package of NuSMV version 2. 
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


#ifndef __HRC_DUMPER_H__
#define __HRC_DUMPER_H__


#include "utils/object.h"

#include "hrc/HrcNode.h"
#include "compile/symb_table/SymbTable.h"
#include "node/node.h"
#include "prop/Prop.h"
#include "utils/utils.h"


/**Type***********************************************************************

  Synopsis    [Definition of the public accessor for class HrcDumper]

  Description []

******************************************************************************/
typedef struct HrcDumper_TAG*  HrcDumper_ptr;


/**Macros**********************************************************************

  Synopsis    [To cast and check instances of class HrcDumper]

  Description [These macros must be used respectively to cast and to check
  instances of class HrcDumper]

******************************************************************************/
#define HRC_DUMPER(self) \
         ((HrcDumper_ptr) self)

#define HRC_DUMPER_CHECK_INSTANCE(self) \
         (nusmv_assert(HRC_DUMPER(self) != HRC_DUMPER(NULL)))



/**Type***********************************************************************

  Synopsis    []

  Description []

******************************************************************************/
typedef enum HrcDumperSnippet_TAG {

  HDS_HRC_TOP, /* top level */

  HDS_LIST_MODS, /* list of modules, used for initial/final
                    comments and/or headers */
  HDS_MOD, /* module begins/ends */

  HDS_MOD_NAME, /* module name */

  HDS_LIST_MOD_FORMAL_PARAMS, /* module formal parameters */
  HDS_MOD_FORMAL_PARAM, /* single mod parameter */

  HDS_LIST_MOD_INSTANCES, /* list of module instances. Use category
                             to know the exact type (VAR, IVAR,...)*/

  HDS_MOD_INSTANCE, /* module instance */

  HDS_MOD_INSTANCE_VARNAME, /* module instance variable name */

  HDS_MOD_INSTANCE_MODNAME, /* module instance module type name */

  HDS_LIST_MOD_INSTANCE_ACTUAL_PARAMS, /* module instance actual parameters */

  HDS_MOD_INSTANCE_ACTUAL_PARAM, /* single mod instance parameter */

  HDS_LIST_SYMBOLS, /* list of symbols (not module instance). Type
                       can be found in SymbCategory */
  HDS_SYMBOL, /* A single symbol (not a module instance). Type can be found in
                 SymbCategory */

  HDS_LIST_ASSIGNS, /* list of assigns */
  HDS_ASSIGN_INIT,
  HDS_ASSIGN_INVAR,
  HDS_ASSIGN_NEXT,

  HDS_LIST_CONSTRAINTS, /* list of constraints */
  HDS_CONSTRAINT_INIT,
  HDS_CONSTRAINT_INVAR,
  HDS_CONSTRAINT_TRANS,

  HDS_LIST_FAIRNESS, /* list of justice/compassion */
  HDS_JUSTICE,
  HDS_COMPASSION,

  HDS_LIST_SPECS, /* list of specifications */
  HDS_SPEC, /* single specification. Type in */

  HDS_LIST_COMPILER_INFO, /* compiler information */
  HDS_LIST_SYNTAX_ERRORS, /* list of all syntactic errors, when available */
  HDS_ERROR, /* a single error */

} HrcDumperSnippet;



/**Type***********************************************************************

  Synopsis    []

  Description []

******************************************************************************/
typedef struct HrcDumperInfo_TAG {

  enum {
    HRC_STAGE_BEGIN = 1,
    HRC_STAGE_END = 2,
    HRC_STAGE_BEGIN_END = HRC_STAGE_BEGIN | HRC_STAGE_END,
  } stage;

  union {
    node_ptr name;
    node_ptr value;
    node_ptr expr;
  } n1;

  union {
    node_ptr type;
    node_ptr body;
    node_ptr expr;
    int lineno;
  } n2;

  struct {   /* for errors */
    int lineno;
    const char* filename; /* can be NULL for stdin */
    const char* message;
    const char* token; /* can be NULL */
  } error;

  SymbCategory symb_cat; /* used for category of symbol(s) */
  Prop_Type spec_type; /* type of specification(s) */

  /* (only for list elements) true iff element is last of the list: */
  boolean last_in_list;

  boolean list_is_empty; /* if the list is empty or not */

  HrcNode_ptr hrcNode; /* the node currently processed */
  
  void* user; /* to carry additional information handled by the user */
} HrcDumperInfo;



/**AutomaticStart*************************************************************/

/*---------------------------------------------------------------------------*/
/* Function prototypes                                                       */
/*---------------------------------------------------------------------------*/

EXTERN HrcDumper_ptr HrcDumper_create ARGS((FILE* fout));
EXTERN void HrcDumper_destroy ARGS((HrcDumper_ptr self));

EXTERN VIRTUAL void HrcDumper_dump_snippet ARGS((HrcDumper_ptr self,
                                                 HrcDumperSnippet snippet,
                                                 const HrcDumperInfo* info));

EXTERN void HrcDumper_enable_indentation ARGS((HrcDumper_ptr self, 
                                               boolean flag));
EXTERN void HrcDumper_inc_indent ARGS((HrcDumper_ptr self));
EXTERN void HrcDumper_dec_indent ARGS((HrcDumper_ptr self));

EXTERN void HrcDumper_enable_mod_suffix ARGS((HrcDumper_ptr self, 
                                              boolean flag));


/**AutomaticEnd***************************************************************/



#endif /* __HRC_DUMPER_H__ */
