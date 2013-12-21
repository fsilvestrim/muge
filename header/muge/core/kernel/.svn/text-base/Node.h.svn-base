#ifndef __muge__core__kernel__Node_h__
#define __muge__core__kernel__Node_h__

#include <map>
using namespace std;

#include "EventDispatcher.h"
using namespace muge::core::event;

#include "Process.h"
#include "Attribute.h"
using namespace muge::core::kernel;

#include "AbstractManager.h"
using namespace muge::utils::manager;

#pragma GCC visibility push(default)
namespace muge
{
	namespace core
	{
		namespace kernel
		{
			class Node: public AbstractManager<Node>, public EventDispatcher, public virtual Process
			{
			public:
				enum OPERATION {
					STOP,
					EXECUTE,
					STEP,
					BUILD,
					DESTROY,
					LINKAGE
				};
				
				enum STATE {
					ACTIVE,
					INACTIVE,
					IDLE,
					SPECTATOR
				};
				
				enum PHASE {
					NOT_INTERPRETED,
					INTERPRETED		
				};
				
			private:
				const char		*name;
				const char		*id;
				const char		*type;
				
				int				depth;
				int				index;
				Node			*root;
				Node			*parent; //NodeContainer
				void			recursiveDepth(Node *);
				
				STATE			oldState, state;
				PHASE			phase;
				
			protected:
				
				map<int, Attribute*>			attributes;
				map<int, Attribute*>::iterator	it_attributes;
				
			public:	
				Node(const char*, int = 0, Node* = NULL);
				~Node();
				
				int				getDepth();
				int				getIndex();
				
				const char		*getId();
				const char		*getType();
				const char		*getName();
				void			setId(const char *);
				void			setName(const char *);
				
				void			updateState();
				void			changeState(STATE value);
				void			changePhase(PHASE value);
				STATE			getOldState();
				STATE			getState();
				PHASE			getPhase();
				
				Node			*getRoot();
				Node			*getParent();
				Node			*addChild(Node *);
				Node			*getChildById(const char *);
				Node			*getChildByName(const char *);
				
				void			addAttribute(int, Attribute*);
				Attribute		*getAttribute(int);
				const char		*getAttributeByKey(const char *);
				
				void			activateNodeChild();
				void			executeOperation(OPERATION op);
				void			recursiveOperation(OPERATION op);
				void			lookChildren(void (*callBack)(Node *));
				void			recursiveSearch(void (*callBack)(Node *));
				
				void			printNode(Node *);
				void			explode();
			};
		}
	}
}
#pragma GCC visibility pop
#endif
