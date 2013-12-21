/*
 *  XMLParser.cpp
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 11/18/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "XMLParser.h"
#include "DIGEOElement.h"
#include "DIGEOGame.h"
#include "DIGEOAction.h"
#include "DIGEOBound.h"
#include "DIGEOCamera.h"
#include "DIGEODisplay.h"
#include "DIGEOEventDispatcher.h"
#include "DigeoEventListener.h"
#include "DIGEOInput.h"
#include "DIGEOLevel.h"
#include "DIGEOObject.h"
#include "DIGEOResource.h"
#include "DIGEOScore.h"
#include "DIGEOUser.h"
#include "DIGEOCamera.h"
#include "DIGEOViewpoint.h"
#include "DIGEOConfig.h"
#include "DIGEOKey.h"
#include "DIGEOGui.h"

#include "Attribute.h"

#include <string>
#include <iostream>
#include <tinyXML/tinyXML.h>

using namespace muge::elements;
using namespace muge::elements::language;
using namespace muge::core::kernel;
using namespace muge::utils::parser;


/******** Parser DIGEOElements **********/
DIGEOElement *createSpecificElement(const char *tagName)
{
	void *element = NULL;
	
	if(!strcmp (tagName, DIGEOSintax::DIGEO_Digital_Game)) {
		element	= new DIGEOGame(tagName);
	}
	else if(!strcmp (tagName, DIGEOSintax::DIGEO_Resource)) {
		element = new DIGEOResource(tagName);
	}
	else if(!strcmp (tagName, DIGEOSintax::DIGEO_EI_Input)) {
		element = new DIGEOInput(tagName);
	}
	else if(!strcmp (tagName, DIGEOSintax::DIGEO_EII_Key)) {
		element = new DIGEOKey(tagName);
	}
	else if(!strcmp (tagName, DIGEOSintax::DIGEO_EDDi_Camera)) {
		element = new DIGEOCamera(tagName);
	}
	else if(!strcmp (tagName, DIGEOSintax::DIGEO_ED_Bound)) {
		element = new DIGEOBound(tagName);
	}
	else if(!strcmp (tagName, DIGEOSintax::DIGEO_EDO_Dynamic)) {
		element = new DIGEOObject(tagName, DIGEOObject::DYNAMIC);
	}
	else if(!strcmp (tagName, DIGEOSintax::DIGEO_EDO_Static)) {
		element = new DIGEOObject(tagName, DIGEOObject::STATIC);
	}	
	else if(!strcmp (tagName, DIGEOSintax::DIGEO_Language_Load)) {
		element = new DIGEOLanguage(tagName);
	}
	else if(!strcmp (tagName, DIGEOSintax::DIGEO_Language_Config)) {
		element = new DIGEOConfig(tagName);
	}
	else if(!strcmp (tagName, DIGEOSintax::DIGEO_EDUi_VisualComponent)) {
		element = new DIGEOGui(tagName);
	}
	else if(!strcmp (tagName, DIGEOSintax::DIGEO_EIACv_Move)) {
		element = new DIGEOAction(tagName, DIGEOAction::MOVE);
	}
	else if(!strcmp (tagName, DIGEOSintax::DIGEO_EIA_ChangeValue)) {
		element = new DIGEOAction(tagName, DIGEOAction::CHANGE_VALUE);
	}
	else if(!strcmp (tagName, DIGEOSintax::DIGEO_EBT_Hit)) {
		element = new DIGEOAction(tagName, DIGEOAction::HIT);
	}
	else if(!strcmp (tagName, DIGEOSintax::DIGEO_EI_EventDispatcher)) {
		element = new DIGEOEventDispatcher(tagName);
	}
	else if(!strcmp (tagName, DIGEOSintax::DIGEO_EB_EventListener)) {
		element = new DIGEOEventListener(tagName);
	}
	else {
		element = new DIGEOElement(tagName);
	}

	return (DIGEOElement*)element;
}

/******** Parser Node **********/
int parseAttribs(TiXmlElement* pElement, DIGEOElement *node = NULL, unsigned int indent = 0)
{
	if ( !pElement ) return 0;
	
	TiXmlAttribute* pAttrib = pElement->FirstAttribute();
	int				i=0;

	while (pAttrib)
	{
		if (node != NULL) {
			Attribute *atValue	= new Attribute;
			atValue->setKey(pAttrib->Name());
			atValue->setValue(pAttrib->Value());
			
			node->addAttribute(i, atValue);
		}
		
		i++;
		pAttrib = pAttrib->Next();
	}
	
	if (node != NULL) {
		//setting the attributes to the node
		node->setId(node->getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_id));
		node->setName(node->getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_name));
	}
	
	return i;	
}

void parseNode( TiXmlNode* pParent, DIGEOElement *parent = NULL, unsigned int indent = 0)
{
	if ( !pParent ) return;
	
	DIGEOElement		*element = NULL;
	TiXmlNode			*pChild;
	int					type = pParent->Type();

	switch ( type )
	{
		case TiXmlNode::ELEMENT:			
			//create
			element = createSpecificElement(pParent->Value());
			
			//hierarchy
			if (parent == NULL)	DIGEOManager::getInstance()->game = element;
			else				parent->addChild(element);
			
			//attributes
			parseAttribs(pParent->ToElement(), element, indent+1);
			
			//build -> create
			element->build();
			
			break;
			
		default:
			break;
	}
	
	for ( pChild = pParent->FirstChild(); pChild != 0; pChild = pChild->NextSibling()) 
		parseNode( pChild, element, indent+1);
}

/******** Class **********/
void XMLParser::load(const char *filename)
{	
	TiXmlDocument doc(filename);
	
	if(doc.LoadFile())
	{
		TiXmlHandle		handle(&doc);
		parseNode(&doc);
		
		//DIGEOManager::getInstance()->game->explode();
	}
}
