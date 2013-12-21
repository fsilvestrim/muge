/*
 *  BooleanExpression.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 11/24/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__utils__parser__SExpParser_h__
#define __muge__utils__parser__SExpParser_h__

#include "SExpression.h"
#include <map>

#pragma GCC visibility push(default)
namespace muge
{
	namespace utils
	{
		namespace parser
		{
			class AddExpression: public NonTerminalExpression 
			{
				override public function get weight():int { return 1};
				
				override public function evaluate() : Number
				{
					return getLeftNode().evaluate() + getRightNode().evaluate();
				}
				
				public function AddExpression(l : Expression,  r : Expression) : void
				{
					super(l, r);
				}
			}
			
			class SubtractExpression: public NonTerminalExpression 
			{
				override public function get weight():int { return 1};
				
				override public function evaluate() : Number
				{
					return getLeftNode().evaluate() - getRightNode().evaluate();
				}
				
				public function SubtractExpression(l : Expression,  r : Expression) : void
				{
					super(l, r);
				}
			}
			
			class MultiplyExpression: public NonTerminalExpression 
			{
				override public function get weight():int { return 3};
				
				override public function evaluate() : Number
				{
					return getLeftNode().evaluate() * getRightNode().evaluate();
				}
				
				public function MultiplyExpression(l : Expression,  r : Expression) : void
				{
					super(l, r);
				}
			}
			
			class DivisionExpression: public NonTerminalExpression 
			{
				override public function get weight():int { return 2};
				
				override public function evaluate() : Number
				{
					return getLeftNode().evaluate() / getRightNode().evaluate();
				}
				
				public function DivisionExpression(l : Expression,  r : Expression) : void
				{
					super(l, r);
				}
			}
			
			/******************************/
			class SExpParser
			{
			private:
				const char	*mathFormule;
				const char	*boolFormule;
				Node		*expressionTree;
				
				map<const char*, SExpression*>	operators;
				map<const char*, SExpression*>::iterator	it_operators;
				
				private function generateExpressions ( node : TreeNode ) : void
				{
					node.data = generateExpression(node.data)
				}
				
				private function processNode ( node : TreeNode ) : void
				{
					if (node.hasChildren() && !(node.data is Array))
					{
						var arrData : Array = [];
						
						for each ( var n : TreeNode in node.children.toArray())
						{
							arrData.push(n.data);
						}
						
						node.data = solveExpression(arrData)[0];
					}
				}
				
				private function solveExpression ( arrExp : Array ) : Array
				{
					var arrCopy 		: Array = arrExp;
					var posMaxExp 		: int 	= -1;
					var weightExp 		: int 	= -1;
					var expNonTermCount : int 	= 0;
					
					var expNonTerm		: NonTerminalExpression;
					var expression		: Expression;
					
					for each ( var e : Expression in arrCopy )
					{
						if (e is NonTerminalExpression) 
						{
							if (e.weight > weightExp)
							{
								expNonTerm 	= NonTerminalExpression(e);
								posMaxExp	= arrCopy.indexOf(e);
								expNonTerm.setLeftNode(arrCopy[posMaxExp-1]);
								expNonTerm.setRightNode(arrCopy[posMaxExp+1]);
								weightExp 	= e.weight;	
							}
							expNonTermCount++;
						}
					}
					
					if (expNonTermCount > 0 && arrCopy.length > 1)  
					{
						arrCopy.splice(posMaxExp-1, 3, new TerminalExpression(String(expNonTerm.evaluate())));
						solveExpression(arrCopy);
					}
					
					return arrCopy;
				}
				
			public:
				Parser(const char *mathForm)
				{
					int size		= strlen(mathForm);
					mathFormule		= new char[size+1];
					strcpy((char *)mathFormule,mathForm);
					
					_operators.insert("+", AddExpression);
					_operators.insert("-", SubtractExpression);
					_operators.insert("/", DivisionExpression);
					_operators.insert("*", MultiplyExpression);
				}
				
				public function evaluate() : Number
				{
					recursiveBuildTree(_expressionTree, _mathFormule);			
					TreeIterator.preorder(_expressionTree, generateExpressions);
					TreeIterator.postorder(_expressionTree, processNode);
					
					return TerminalExpression(_expressionTree.data).evaluate();
				}
				
				
			};
		}
	}
}
#pragma GCC visibility pop
#endif


/*
 package
 {
 import com.adobe.utils.StringUtil;
 
 import de.polygonal.ds.HashMap;
 import de.polygonal.ds.TreeIterator;
 import de.polygonal.ds.TreeNode;
 
 public class Parser
 {

 public function Parser(mathFormule : String)
 {
 _mathFormule 	= mathFormule;
 
 _operators.insert("+", AddExpression);
 _operators.insert("-", SubtractExpression);
 _operators.insert("/", DivisionExpression);
 _operators.insert("*", MultiplyExpression);
 }
 
public function evaluate() : Number
{
	recursiveBuildTree(_expressionTree, _mathFormule);			
	TreeIterator.preorder(_expressionTree, generateExpressions);
	TreeIterator.postorder(_expressionTree, processNode);
	
	return TerminalExpression(_expressionTree.data).evaluate();
}

private function generateExpressions ( node : TreeNode ) : void
{
	node.data = generateExpression(node.data)
	}
	
	private function processNode ( node : TreeNode ) : void
	{
		if (node.hasChildren() && !(node.data is Array))
		{
			var arrData : Array = [];
			
			for each ( var n : TreeNode in node.children.toArray())
			{
				arrData.push(n.data);
			}
			
			node.data = solveExpression(arrData)[0];
		}
	}
	
	private function solveExpression ( arrExp : Array ) : Array
	{
		var arrCopy 		: Array = arrExp;
		var posMaxExp 		: int 	= -1;
		var weightExp 		: int 	= -1;
		var expNonTermCount : int 	= 0;
		
		var expNonTerm		: NonTerminalExpression;
		var expression		: Expression;
		
		for each ( var e : Expression in arrCopy )
		{
			if (e is NonTerminalExpression) 
			{
				if (e.weight > weightExp)
				{
					expNonTerm 	= NonTerminalExpression(e);
					posMaxExp	= arrCopy.indexOf(e);
					expNonTerm.setLeftNode(arrCopy[posMaxExp-1]);
					expNonTerm.setRightNode(arrCopy[posMaxExp+1]);
					weightExp 	= e.weight;	
				}
				expNonTermCount++;
			}
		}
		
		if (expNonTermCount > 0 && arrCopy.length > 1)  
		{
			arrCopy.splice(posMaxExp-1, 3, new TerminalExpression(String(expNonTerm.evaluate())));
			solveExpression(arrCopy);
		}
		
		return arrCopy;
	}
	
	private function recursiveBuildTree ( parentNode : TreeNode, str : String ) : void
	{
		var strClean	: String	= StringUtil.replace(str, " ", "");
		var strLen		: int		= strClean.length;
		var arrExp		: Array 	= strClean.split();
		var abre		: Array 	= [];
		var fecha		: Array 	= [];
		var acumString	: String	= "";
		var currChar 	: String;
		var nextChar 	: String;
		
		for (var i : int = 0; i < strLen; i++) 
		{
			currChar 	= strClean.substring(i, i + 1);
			nextChar	= strClean.substring(i + 1, i + 2);
			
			if (currChar == "(")  	
			{		      		
				abre.push(i); 
			}
			else if (currChar == ")")  	
			{ 
				fecha.push(i); 
			}
			else 						
			{ 
				if (abre.length == 0)
				{
					acumString += currChar; 
				}
			}
			
			if (abre.length == fecha.length && abre.length > 0)
			{
				var ini 		: int 		= abre.shift() + 1;
				var end 		: int	 	= fecha.pop();		      		 
				var childNode 	: TreeNode	= new TreeNode(strClean.slice(ini, end), parentNode);
				recursiveBuildTree(childNode, childNode.data);
				
				abre 	= [];
				fecha 	= [];
			}
			
			if (acumString.length > 0 && (i == (strLen-1) || currChar == "(" || isOperator(nextChar) || isOperator(currChar)))
			{
				new TreeNode(acumString, parentNode);
				acumString = "";
			}
		}  
	}
	
	private function generateExpression(expr : String) : Expression
	{
		var e 		: Expression;
		var cla		: Class;
		
		if (!isOperator(expr)) 
		{
			e 	= new TerminalExpression(expr);
		} 
		else 
		{
			cla = Class(_operators.find(expr)) as Class;
			e 	= new cla(null, null);
		}
		
		return e;
	}
		
	private function isOperator( str : String) : Boolean
	{
		return _operators.containsKey(str);
	}
	}
	}
	
	class AddExpression extends NonTerminalExpression 
	{
		override public function get weight():int { return 1};
		
		override public function evaluate() : Number
		{
			return getLeftNode().evaluate() + getRightNode().evaluate();
		}
		
		public function AddExpression(l : Expression,  r : Expression) : void
		{
			super(l, r);
		}
	}
	
	class SubtractExpression extends NonTerminalExpression 
	{
		override public function get weight():int { return 1};
		
		override public function evaluate() : Number
		{
			return getLeftNode().evaluate() - getRightNode().evaluate();
		}
		
		public function SubtractExpression(l : Expression,  r : Expression) : void
		{
			super(l, r);
		}
	}
	
	class MultiplyExpression extends NonTerminalExpression 
	{
		override public function get weight():int { return 3};
		
		override public function evaluate() : Number
		{
			return getLeftNode().evaluate() * getRightNode().evaluate();
		}
		
		public function MultiplyExpression(l : Expression,  r : Expression) : void
		{
			super(l, r);
		}
	}
	
	class DivisionExpression extends NonTerminalExpression 
	{
		override public function get weight():int { return 2};
		
		override public function evaluate() : Number
		{
			return getLeftNode().evaluate() / getRightNode().evaluate();
		}
		
		public function DivisionExpression(l : Expression,  r : Expression) : void
		{
			super(l, r);
		}
	}
	
*/