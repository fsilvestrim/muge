/*
 *  DIGEORessource.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 11/24/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__elements__Resource_h__
#define __muge__elements__Resource_h__

#include "DIGEOElement.h"
using namespace muge::core::kernel;

#include <string>
using namespace std;

#pragma GCC visibility push(default)
namespace muge
{
	namespace elements
	{
		class DIGEOResource: public DIGEOElement
		{
		private:
			const char* texture;
			const char* src;
			
		public:
			enum TYPE {
				BOX,
				SPHERE,
				MESH,
				SOUND,
				BITMAP,
				NONE
			} displayType;
			
			DIGEOResource(const char* tagName, int index = 0, Node* node = NULL):DIGEOElement(tagName, index, node) 
			{
				displayType = NONE;
			};
			
			void build()
			{
				DIGEOElement::build();
				
				if (strcmp(getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_scale), "null")) {
					vector<string> vecScaleStr = getAttributeValues(DIGEOSintax::DIGEO_LanAttr_scale);
					setProperty(DIGEOElement::SCALE, atof(vecScaleStr[0].c_str()), atof(vecScaleStr[1].c_str()), atof(vecScaleStr[2].c_str()));
				}
				
				const char *text = getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_texture);				
				int size	= strlen(text);
				texture		= new char[size+1];
				strcpy((char *)texture,text);
				
				text		= getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_src);				
				size		= strlen(text);
				src			= new char[size+1];
				strcpy((char *)src,text);
				
				if (!strcmp (getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_type), "box"))
					displayType = BOX;
				else if (!strcmp (getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_type), "sphere"))
					displayType = SPHERE;
				else if (!strcmp (getAttributeByKey(DIGEOSintax::DIGEO_LanAttr_type), "mesh"))
					displayType = MESH;
			}
			
			const char *getTexture()
			{
				const char *value = NULL;
				
				if (strcmp(texture, "null")) {
					value = texture;
				}
				
				return value;
			}
			
			const char *getSrc()
			{
				const char *value = NULL;
				
				if (strcmp(src, "null")) {
					value = src;
				}
				
				return value;
			}
		};
	}
}
#pragma GCC visibility pop
#endif