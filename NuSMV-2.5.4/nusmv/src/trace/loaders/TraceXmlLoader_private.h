/**CHeaderFile*****************************************************************

  FileName    [TraceXmlLoader_private.h]

  PackageName [trace.loader]

  Synopsis    [The private header file for the TraceXmlLoader class]

  Description []

  SeeAlso     []

  Author      [Ashutosh Trivedi, Roberto Cavada, Marco Pensallorto]

  Copyright   [
  This file is part of the ``trace'' package of NuSMV version 2.
  Copyright (C) 2010 by FBK-irst.

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

******************************************************************************/
#ifndef __TRACE_XML_LOADER_PRIVATE__H
#define __TRACE_XML_LOADER_PRIVATE__H

#if HAVE_CONFIG_H
# include "nusmv-config.h"
#endif

#include "pkg_traceInt.h"
#include "TraceLoader_private.h"

/* this implementation requires expat */
#include <expat.h>

/*---------------------------------------------------------------------------*/
/* Constant declarations                                                     */
/*---------------------------------------------------------------------------*/
#define EXPAT_BUFSIZE  0x8000 /* 32 kbytes */

#define MAX_ID_LEN     0x3ffe /* 4 kbytes -2 */
#define MAX_VL_LEN     0x3ffe /* 4 kbytes -2 */
#define MAX_EQ_LEN     (4 + MAX_ID_LEN + MAX_VL_LEN) /* 8 kbytes */

/*---------------------------------------------------------------------------*/
/* Macro declarations                                                        */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Type declarations                                                         */
/*---------------------------------------------------------------------------*/


/**Struct**********************************************************************

  Synopsis    [This is the xml loader plugin class]

  Description []

  SeeAlso     []

******************************************************************************/
typedef struct TraceXmlLoader_TAG
{
  INHERITS_FROM(TraceLoader);

  XML_Parser parser;

  /* for xml attributes: */
  /* int type; */

  char* stream_buf;
  char* trace_desc;

  char* xml_filename;

  char* curr_symb; /* last parsed symbol */
  char* curr_val; /* contents of the text stream */

  char* curr_eq;   /* tmp equality buf */
  Trace_ptr trace;/* trace under construction */
  TraceIter step; /* current step to put data into */

  /* parsing flags: */
  TraceXmlTag curr_parsing;
  boolean parse_error;
  unsigned last_time;

  boolean requires_value;

  /* preserve internal parser informations */
  int nusmv_yylineno;
  char* nusmv_input_file;

  NodeList_ptr loopback_states;

  /* a hash table to remember already reported
     undeclared/wrongly-places symbols to avoid reporting them many
     times (this is meaningless if it is not an error to find such
     symbol) */
  hash_ptr all_wrong_symbols;

  /* If true parsing halts when encounters undefined symbols */
  boolean halt_on_undefined_symbols;

  /* If true parsing halts when encounters a symbol in an
     inappropriate section */
  boolean halt_on_wrong_section;

} TraceXmlLoader;


/**AutomaticStart*************************************************************/

/*---------------------------------------------------------------------------*/
/* Function prototypes                                                       */
/*---------------------------------------------------------------------------*/

void trace_xml_loader_init ARGS((TraceXmlLoader_ptr self,
                                 const char* xml_filename,
                                 boolean halt_on_undefined_symbols,
                                 boolean halt_on_wrong_section));

Trace_ptr trace_xml_loader_load ARGS((TraceLoader_ptr loader,
                                      const SymbTable_ptr st,
                                      const NodeList_ptr symbols));

/**AutomaticEnd***************************************************************/

#endif /* __TRACE_XML_PRIVATE__H */

