/*
 *  Expression.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 11/24/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__utils__parser__SExpression_h__
#define __muge__utils__parser__SExpression_h__

#include <stdio.h>

#pragma GCC visibility push(default)
namespace muge
{
	namespace utils
	{
		namespace parser
		{
			class SExpression
			{
			public:
				virtual int			getWeight() = 0;
				virtual float		evaluate()	= 0;
				virtual const char	*toString() = 0;
			};
			
			class TerminalExpression: public SExpression
			{
			private:
				const char *str;
				
			public:
				TerminalExpression(string *s)
				{
					str = s;
				}
				
				int getWeight()
				{
					return 0;
				}
				
				float evaluate()
				{
					return atof(str);
				}
				
				const char *toString()
				{
					return concat("[TerminalExpression] :: ", str);
				}
			};
			
			class NonTerminalExpression: public SExpression
			{
			private:
				Expression *leftNode;
				Expression *rightNode;
				
			public:
				NonTerminalExpression(Expression *l, Expression *r)
				{
					setLeftNode(l);
					setRightNode(r);
				}
				
				void setLeftNode(Expression * node) 
				{
					leftNode = node;
				}
				
				void setRightNode(Expression * node) 
				{
					rightNode = node;
				}
				
				Expression *getLeftNode()
				{
					return leftNode;
				}
				
				Expression *getRightNode() 
				{
					return rightNode;
				}
				
				int getWeight()
				{
					return 0;
				}
				
				float evaluate()
				{
					return atof(str);
				}				
				
				const char *toString()
				{
					return concat("[NonTerminalExpression(", leftNode->toString(), ", ", rightNode->toString(), ")]");
				}
			};
		}
	}
}
#pragma GCC visibility pop
#endif