/*
 *  ScreenManager.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 9/29/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef __muge__ui__ScreenManager_h__
#define __muge__ui__ScreenManager_h__

#include <map>
using namespace std;

#include "Singleton.h"
using namespace muge::utils::designpattern;

#pragma GCC visibility push(default)
namespace muge
{
	namespace elements
	{
		namespace ui
		{
			class DIGEOScreenManager: public Singleton<DIGEOScreenManager>
			{
			public:			
			private:
			};
		}
	}
}
#pragma GCC visibility pop
#endif

//
//
//// ___________________________________________________________________ CONST
//
//// ___________________________________________________________________ CLASS PROPERTIES
//protected var _wasInit			: Boolean	= false;
//
//// ___________________________________________________________________ INSTANCE PROPERTIES		
//static protected var _instance			: ScreenManager;
//protected var _scope					: Sprite;
//protected var _objInit					: Object;
//protected var _map						: Dictionary;
//protected var _view						: DisplayObjectContainer;
//protected var _currentScreen			: AbstractScreen	= null;
//protected var _previousScreen			: AbstractScreen	= null;
//protected var _nextScreen				: AbstractScreen	= null;
//
//// ___________________________________________________________________ GETTERS AND SETTERS
///**
// * Get the main class of the "project"
// * @return An Sprite that represents the main instance
// */
//public function get scope () : Sprite
//{
//	return _scope;
//}
//
///**
// * Get the main View of the ScreenManager
// * @return An DisplayObjectContainer that represents the main stage of the instance
// */
//public function get view () : DisplayObjectContainer
//{
//	return _view;
//}
//
///**
// * Get the current Screen
// * @return The instance of the actual Screen
// */
//public function get currentScreen () : AbstractScreen
//{
//	return _currentScreen;
//}
//
///**
// * Get an Screen by name
// * @param	An string that represents the screen name
// * @return An AbstractScreen Sub Class that have as name the param passed
// */
//public function getScreen ( name : String ) : AbstractScreen
//{
//	return _map[name];
//}
//
///**
// * This is an auxiliar object.
// * This reference is related an object passed in the init of the ScreenManager.
// * This object serve to do not need long references.
// * @return An Object 
// */
//public function get objInit():Object { return _objInit; }
//
///**
// * Get the previous Screen
// * @return an AbstractScreen Sub Class instance
// */
//public function get previousScreen():AbstractScreen { return _previousScreen; }
//// ___________________________________________________________________ CONSTRUCTOR
//public function ScreenManager(scope : Sprite = null, container : DisplayObjectContainer = null, obj : Object = null) : void 
//{
//	if (container != null)
//		init(scope, container, obj);
//		}
//
//// ___________________________________________________________________ PUBLIC METHODS
///**
// */
//static public function getInstance() : ScreenManager
//{
//	if ( _instance == null ) 
//		_instance = new ScreenManager();
//		
//		return _instance;
//}
//
///**
// * Initilize the ScreenManager.
// * @param the main container of the screens
// * @param an init Object that serves to auxiliar in internal refereces
// * @example
// * <listing version="3.0">
// * package
// {
// import com.w3haus.scene.ScreenManager;
// import com.w3haus.ui.ScreenLock;
// 
// import flash.display.Sprite;
// 
// public class MainClass extends Sprite
// {
// //this sprite represents the backgound of the site
// private var _backLayer 		: Sprite;
// //this sprite represents the main container of the ScreenManager
// //here is where the screens will be added and removed
// private var _middleLayer 	: Sprite;
// //this sprite will hold the ScreenLock (to do not able the mouse hit in the transictions)
// private var _upLayer 		: Sprite;
// 
// //this screen will load external swf's files
// private var _screen1		: ScreenWithLoad;
// //this is a common Screen
// private var _screens		: ScreenWithoutLoad;
// 
// private var _lock 			: ScreenLock;
// 
// public function MainClass()
// {
// _backLayer		= new Sprite();
// _middleLayer	= new Sprite();
// _upLayer		= new Sprite();
// 
// addChild(_backLayer);
// addChild(_middleLayer);
// addChild(_upLayer);
// 
// _lock			= new ScreenLock();
// _upLayer.addChild(_lock);
// 
// ScreenManager.getInstance().init(_middleLayer, {lock: _lock});
// ScreenManager.getInstance().addScreen(new ScreenWithLoad("Screen1")); //mainly use Globals like Globals.SCREEN_ETC, instead literally strings
// ScreenManager.getInstance().addScreen(new ScreenWithoutLoad("Screen2"));
// ScreenManager.getInstance().changeToScreen("Screen1");
// }
// 
// }
// }
// * </listing>
// */
//public function init(scope : Sprite, container : DisplayObjectContainer, obj : Object = null) : void 
//{
//	if (!_wasInit)
//	{
//		_scope		= scope;
//		_map		= new Dictionary(true);
//		_view		= container;
//		_wasInit 	= true;
//		_map[null]	= null;
//		
//		if (obj != null)
//			_objInit = obj;
//			}
//}
//
///**
// * Method used to add new Screens for that ScreenManager can hold
// * @param An AbstractScreen Sub Class (please dont forget the name of the Screen)
// * @return An Boolean value that represents if the Screen was added or not
// * @see #AbstractScreen AbstractScreen
// */
//public function addScreen ( screen : AbstractScreen ) : Boolean
//{
//	var value : Boolean = false;
//	
//	if ( !isRegistered(screen) )
//	{
//		_map[screen.name] = screen;
//		
//		value = true;
//	}
//	
//	return value;
//}
//
///**Metthod user to remove an Screen from the memory
// * 
// * @param An AbstractScreen Sub Class
// * @return An Boolean value that represents if the Screen was removed or not
// */
//public function remScreen ( screen : AbstractScreen ) : Boolean
//{
//	var value : Boolean = false;
//	
//	if( isRegistered(screen) )
//	{
//		//TODO: validar quando a tela corrente estiver em transitionOUT
//		AbstractScreen(_map[screen.name]).hide();
//		delete _map[screen.name];
//		value = true;
//	}
//	
//	return value;
//}
//
///**
// * Verify if an Screen exists in the Screen Manager
// * @param	screen 			the Screen to be verified
// * @return 	an Boolean values that represents if it exists or not
// */
//public function isRegistered ( screen : AbstractScreen ) : Boolean
//{
//	return _map[screen.name] != undefined;
//}
//
//
///**
// * Change for other screen
// * @param	name  			the name of the screen to be changed
// * @param 	forceRebuild	an boolean that make the screen rebuild or not (if trying to change to the same Screen)
// */
//public function changeToScreen ( name : String, forceRebuild : Boolean = false ) : void
//{
//	_nextScreen = _map[name];
//	
//	if (name == null)
//		outPrevScreen();
//		else if ( _nextScreen != _currentScreen || forceRebuild )
//		{
//			if ( _currentScreen != null )
//				outPrevScreen();
//				else
//					checkPreloader();
//					}
//}
//
//// ___________________________________________________________________ PRIVATE METHODS
///**
// * @private
// */
//private function outPrevScreen () : void
//{
//	_previousScreen = _currentScreen;
//	_previousScreen.addEventListener(ScreenEvent.HIDE_FINISH, prevFinishOutHandler);
//	_previousScreen.hide();
//}
//
///**
// * @private
// */
//private function checkPreloader () : void
//{
//	if(_nextScreen.havePreloader && !_nextScreen.wasContentLoaded)
//	{
//		_nextScreen.addEventListener (ScreenEvent.PRELOAD, onInitIn);
//		_nextScreen.preloadAssets();
//	}
//	else
//	{
//		onInitIn();
//	}
//}
//
///**
// * @private
// */
//private function removeScreen () : void
//{
//	_scope.stage.focus = _scope;
//	_view.removeChild(MovieClip(_previousScreen));
//	_currentScreen = null;
//}
//// ___________________________________________________________________ EVENTS
///**
// * @private
// */
//private function prevFinishOutHandler(e:Event = null):void 
//{
//	if(e) e.stopImmediatePropagation();
//		
//		_previousScreen.removeEventListener(ScreenEvent.HIDE_FINISH, prevFinishOutHandler);
//		
//		if(_nextScreen == null)
//			removeScreen();
//			else
//				checkPreloader()
//				}
//
///**
// * @private
// */
//private function onInitIn ( e : Event = null ) : void
//{
//	if(e) e.stopImmediatePropagation();
//		
//		if (_previousScreen != null)
//			if (!_previousScreen.isVisible)
//				removeScreen();
//				
//				_nextScreen.removeEventListener (ScreenEvent.PRELOAD, onInitIn);
//				_currentScreen 		= _nextScreen;
//				_view.addChild(MovieClip(_currentScreen));
//				_currentScreen.show();
//				}