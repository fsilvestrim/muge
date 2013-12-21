#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "Log.h"
using namespace muge::utils::debug;

#include "Node.h"
using namespace muge::core::kernel;

#include "StringUtil.h"
using namespace muge::utils::str;


Node::Node(const char *name, int index, Node *parent)
{
	int size				= strlen(name);
	type					= new char[size+1];
	strcpy((char *)type,name);
	
	this->index				= index;
	this->parent			= parent;
	state					= INACTIVE;
	phase					= NOT_INTERPRETED;
}

Node::~Node()
{
	this->index		= 0;
	this->parent	= 0;
}


/**************** Reference ****************/
void Node::setId(const char* str)
{
	int size	= strlen(str);
	id			= new char[size+1];
	strcpy((char *)id,str);
}

void Node::setName(const char* str)
{
	int size	= strlen(str);
	name		= new char[size+1];
	strcpy((char *)name,str);
}

const char *Node::getId()
{
	return id;
}

const char *Node::getName()
{
	return name;
}

const char *Node::getType()
{
	return type;
}

void Node::updateState()
{
	oldState	= state;
}

void Node::changeState(STATE value)
{
	if (value != getState()) {
		oldState	= state;
		state		= value;
	}
}

void Node::changePhase(PHASE value)
{
	phase	= value;
}

Node::STATE Node::getOldState()
{
	return oldState;
}

Node::STATE Node::getState()
{
	return state;
}

Node::PHASE Node::getPhase()
{
	return phase;
}


/**************** Hyerarchy ****************/
int Node::getIndex()
{
	return this->index;
}

Node *Node::getParent()
{
	return parent;
}

Node *Node::addChild(Node* node)
{
	childrens[(const char*)numChildren++] = node;
	node->parent = this;
	
	return node;
}


/**************** Attribute ****************/
void  Node::addAttribute(int index, Attribute *value)
{
	attributes[index] = value;
}

Attribute *Node::getAttribute(int index)
{
	return attributes[index];
}

const char *Node::getAttributeByKey(const char *key)
{
	Attribute *data = NULL;
	for ( it_attributes = attributes.begin(); it_attributes != attributes.end(); it_attributes++ )
	{
		data = (*it_attributes).second;
		
		if (data)
		{
			if (!strcmp(data->getKey(), key)) {
				return data->getValue();
			}
		}
	}
	
	return "null";
}


/**************** Search ****************/
Node *Node::getChildById(const char *id)
{	
	Node *child			= NULL;
	Node *node			= NULL;


	if (!strcmp(getId(), id)) {
		return this;
	}
	
	for ( it_childrens = childrens.begin() ; it_childrens != childrens.end(); it_childrens++ )
	{
		child = (*it_childrens).second;
		
		if (child->getNumChildrens() >= 0) 
			node = child->getChildById(id);
		else 		
			node = this;
		
		if (node) 
			break;
	}
	
	return node;
}

Node *Node::getChildByName(const char *name)
{	
	Node *node = NULL;
	
	for ( it_childrens = childrens.begin() ; it_childrens != childrens.end(); it_childrens++ )
	{
		node = (*it_childrens).second;
		
		if (!strcmp(id, node->getName()))	break;
		if (node->getNumChildrens() > 0)	node->getChildByName(name);
	}
	
	return node;
}

void Node::lookChildren(void (*callBack)(Node *))
{
	Node *child = NULL;
	
	for ( it_childrens = childrens.begin() ; it_childrens != childrens.end(); it_childrens++ )
	{
		child = (*it_childrens).second;
		callBack(child);
	}
}

void Node::recursiveSearch(void (*callBack)(Node *))
{
	Node *node = NULL;
	
	for ( it_childrens = childrens.begin() ; it_childrens != childrens.end(); it_childrens++ )
	{
		node = (*it_childrens).second;
		callBack(node);
		
		if (node->getNumChildrens() > 0)	
			node->recursiveSearch(callBack);
	}
}

/**************** Auxiliar ****************/
int Node::getDepth()
{
	depth = 0;
	recursiveDepth(this);
	
	return depth;
}

void Node::recursiveDepth(Node *node)
{
	if (node->parent != NULL) {
		depth++;
		recursiveDepth(node->parent);
	}
}

void Node::activateNodeChild()
{
	Node *child = NULL;
	
	for ( it_childrens = childrens.begin() ; it_childrens != childrens.end(); it_childrens++ )
	{
		child = (*it_childrens).second;
		child->changeState(ACTIVE);
	}
	
}

void Node::executeOperation(OPERATION op)
{
	switch (op) {
		case EXECUTE:
			execute();
			break;
		default:
			break;
	}
}

void Node::recursiveOperation(OPERATION op)
{
	Node *child;
	
	executeOperation(op);
		
	for ( it_childrens = childrens.begin() ; it_childrens != childrens.end(); it_childrens++ )
	{
		child = (*it_childrens).second;
		if (child->getNumChildrens() > 0) 
			child->recursiveOperation(op);
		else 		
			child->executeOperation(op);
	}
}

/**************** Debug ****************/
void Node::printNode(Node *node)
{	
	int depth		= node->getDepth();
	string tab;
	
	for (int i = 0; i < depth; i++) 
		tab.append("---");
	
	Log::printf(2, tab.c_str(), node->getType());
	
	Attribute *data = NULL;
	for ( node->it_attributes = node->attributes.begin(); node->it_attributes != node->attributes.end(); node->it_attributes++ )
	{
		data = (*node->it_attributes).second;
		if (data) Log::printf(4, " --- Data :: key = ", data->getKey(), ", value = ", data->getValue());
	}
}

void Node::explode()
{	
	Node *child;
	
	printNode(this);
	
	for ( it_childrens = childrens.begin() ; it_childrens != childrens.end(); it_childrens++ )
	{
		child = (*it_childrens).second;
		if (child->getNumChildrens() > 0) 
			child->explode();
		else 		
			printNode(child);
	}
}