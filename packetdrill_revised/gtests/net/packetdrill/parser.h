/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ELLIPSIS = 258,
     SA_FAMILY = 259,
     SIN_PORT = 260,
     SIN_ADDR = 261,
     _HTONS_ = 262,
     INET_ADDR = 263,
     MSG_NAME = 264,
     MSG_IOV = 265,
     MSG_FLAGS = 266,
     FD = 267,
     EVENTS = 268,
     REVENTS = 269,
     ONOFF = 270,
     LINGER = 271,
     ACK = 272,
     ECR = 273,
     EOL = 274,
     MSS = 275,
     NOP = 276,
     SACK = 277,
     SACKOK = 278,
     TIMESTAMP = 279,
     VAL = 280,
     WIN = 281,
     WSCALE = 282,
     PRO = 283,
     NO_CHECK = 284,
     FAST_OPEN = 285,
     ECT0 = 286,
     ECT1 = 287,
     CE = 288,
     ECT01 = 289,
     NO_ECN = 290,
     IPV4 = 291,
     IPV6 = 292,
     ICMP = 293,
     UDP = 294,
     GRE = 295,
     MTU = 296,
     MPLS = 297,
     LABEL = 298,
     TC = 299,
     TTL = 300,
     OPTION = 301,
     FLOAT = 302,
     INTEGER = 303,
     HEX_INTEGER = 304,
     WORD = 305,
     STRING = 306,
     BACK_QUOTED = 307,
     CODE = 308,
     IPV4_ADDR = 309,
     IPV6_ADDR = 310
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 438 "parser.y"

	s64 integer;
	double floating;
	char *string;
	char *reserved;
	s64 time_usecs;
	enum direction_t direction;
	enum ip_ecn_t ip_ecn;
	struct mpls_stack *mpls_stack;
	struct mpls mpls_stack_entry;
	u16 port;
	s32 window;
	u32 sequence_number;
	struct {
		int protocol;		/* IPPROTO_TCP or IPPROTO_UDP */
		u32 start_sequence;
		u16 payload_bytes;
	} tcp_sequence_info;
	struct option_list *option;
	struct event *event;
	struct packet *packet;
	struct syscall_spec *syscall;
	struct command_spec *command;
	struct code_spec *code;
	struct tcp_option *tcp_option;
	struct tcp_options *tcp_options;
	struct expression *expression;
	struct expression_list *expression_list;
	struct errno_spec *errno_info;



/* Line 2068 of yacc.c  */
#line 138 "parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;

