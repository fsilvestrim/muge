/*
 *  AbstractScreen.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 9/29/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__ui__AbstractScreen_h__
#define __muge__ui__AbstractScreen_h__

#include "DIGEOVisualComponent.h"

#pragma GCC visibility push(default)
namespace muge
{
	namespace elements
	{
		namespace ui
		{
			class DIGEOAbstractScreen: public DIGEOVisualComponent
			{
			public:			
			private:
			};
		}
	}
}
#pragma GCC visibility pop
#endif


//public class AbstractScreen extends MovieClip
//{
//	// ___________________________________________________________________ CONST
//	
//	// ___________________________________________________________________ CLASS PROPERTIES
//	private static var screenNumber	: int 		= 0;
//	protected var _isFirstShow		: Boolean 	= true;
//	protected var _isVisible		: Boolean 	= true;
//	protected var _havePreloader	: Boolean 	= false;
//	protected var _wasContentLoaded	: Boolean 	= false;
//	protected var _isRendering		: Boolean 	= false;
//	protected var _hasTransitionIn	: Boolean 	= false;
//	protected var _hasTransitionOut	: Boolean 	= false;
//	protected var _name				: String;
//	protected var _preloaderContent	: *;
//	
//	// ___________________________________________________________________ INSTANCE PROPERTIES
//	/**
//	 * Event dispatched when start's the show screen
//	 */
//	protected var _eOnShowInit		: ScreenEvent;
//	
//	/**
//	 * Event dispatched when the transition In ends
//	 */
//	protected var _eOnShowFinish	: ScreenEvent;
//	
//	/**
//	 * Event dispatched when start's the hide screen
//	 */
//	protected var _eOnHideInit		: ScreenEvent;
//	
//	/**
//	 * Event dispatched when the transition Out ends
//	 */
//	protected var _eOnHideFinish	: ScreenEvent;
//	
//	/**
//	 * Event dispatched when the preloader says that is complete
//	 */
//	protected var _eOnPreload		: ScreenEvent;
//	
//	protected var _objAux			: Object	= new Object();
//	
//	// ___________________________________________________________________ GETTERS AND SETTERS
//	/**
//	 * If the screen is at the main container
//	 */	
//	public function get isVisible()			: Boolean		{ return _isVisible; }
//	
//	/**
//	 * If the screen have preloader
//	 */	
//	public function get havePreloader () 	: Boolean 		{ return _havePreloader; }
//	
//	/**
//	 * If is the first time that the screen is beeing showed
//	 */
//	public function get isFirstShow()		: Boolean 		{ return _isFirstShow; }
//	
//	/**
//	 * The name of the screen
//	 */
//	public override function get name()		: String 		{ return _name; }
//	
//	/**
//	 * The Content preloaded if in memory
//	 */
//	public function get preloaderContent()	: * 			{ return _preloaderContent; }
//	
//	/**
//	 * To know if the content was loaded
//	 */
//	public function get wasContentLoaded()	: Boolean	 	{ return _wasContentLoaded; }
//	
//	public function get objAux () : Object					{ return _objAux; }
//	
//	// ___________________________________________________________________ CONSTRUCTOR
//	/**
//	 * Constructs a new AbstractScreen instance.
//	 * @param the name of the screen
//	 * @param if this Screen have transition In associated
//	 * @param if this Screen have transition Out associated
//	 * @param if this Screen have to preload something
//	 */
//	public function AbstractScreen ( name : String = null, transitionIn : Boolean = false, transitionOut : Boolean = false, preloader : Boolean = false ) 
//	{
//		_name				= name == null ? ("default_" + (++screenNumber)) : name;
//		_isFirstShow		= true;
//		_hasTransitionIn 	= transitionIn;
//		_hasTransitionOut	= transitionOut;
//		_havePreloader		= preloader;
//		
//		_eOnShowInit		= new ScreenEvent( ScreenEvent.SHOW_INI, this );
//		_eOnShowFinish		= new ScreenEvent( ScreenEvent.SHOW_FINISH, this );
//		_eOnHideInit		= new ScreenEvent( ScreenEvent.HIDE_INI, this );
//		_eOnHideFinish		= new ScreenEvent( ScreenEvent.HIDE_FINISH, this );
//		_eOnPreload			= new ScreenEvent( ScreenEvent.PRELOAD, this );
//		
//		addEventListener(ScreenEvent.HIDE_FINISH, destroyHandler);
//	}
//	
//	// ___________________________________________________________________ PUBLIC METHODS		
//	/**
//	 * Force the show of this screen
//	 */
//	final public function show () : void
//	{
//		build();
//		_isVisible = _isRendering = true;
//		
//		disable();
//		dispatchEvent(_eOnShowInit);
//		
//		if (_hasTransitionIn)
//		{
//			transitionIn();
//		}
//		else
//		{
//			enable();
//			dispatchEvent(_eOnShowFinish);
//		}
//	}
//	
//	/**
//	 * Force this Screen to be hided
//	 */
//	final public function hide () : void
//	{
//		_isRendering = false;
//		
//		disable();
//		dispatchEvent(_eOnHideInit);
//		
//		if (_hasTransitionOut)
//		{
//			transitionOut();
//		}
//		else
//		{
//			dispatchEvent(_eOnHideFinish);
//		}
//		
//		if ( _isFirstShow ) { _isFirstShow = false; }
//	}
//	
//	/**
//	 * Override the build method
//	 * This method is used in the inicialization of the screen
//	 * @example
//	 * <listing version="3.0">
//	 package
//	 {
//	 import com.w3haus.scene.AbstractScreen;
//	 import com.w3haus.scene.ScreenManager;
//	 
//	 import flash.display.Sprite;
//	 
//	 public class ScreenWithoutLoad extends AbstractScreen
//	 {
//	 
//	 private var _image : Sprite;
//	 
//	 public function ScreenWithoutLoad(name:String)
//	 {
//	 super(name, true, true, true);
//	 }
//	 
//	 override public function build():void
//	 {
//	 _image 				= new Sprite();
//	 _image.alpha		= 0;
//	 
//	 addChild(_image);
//	 }
//	 
//	 override public function destroy():void
//	 {
//	 removeChild(_image);	
//	 }
//	 
//	 override protected function enable():void
//	 {
//	 ScreenManager.getInstance().objInit.lock.hide();
//	 }
//	 
//	 override protected function disable():void
//	 {
//	 ScreenManager.getInstance().objInit.lock.show();
//	 }
//	 
//	 override protected function transitionIn():void
//	 {
//	 Tweener.addTween(_image, {alpha:1, time:1, onComplete:super.endTransitionIn });
//	 }
//	 
//	 override protected function transitionOut():void
//	 {
//	 Tweener.addTween(_image, {alpha:0, time:1, onComplete:super.endTransitionOut });
//	 }
//	 }
//	 }
//	 * </listing>
//	 */
//	public function build():void
//	{
//		throw new Error ("Hey!!! Implements Build on AbstractScreen.build!");
//	}
//	
//	/**
//	 * Override the destroy method
//	 * This method is used in the finalization (after the transition out) of the screen
//	 */
//	public function destroy():void
//	{
//		throw new Error ("Hey!!! Implements Destroy on AbstractScreen.destroy!");
//	}
//	
//	/**
//	 * Override this method to preload the assets
//	 * @example
//	 * <listing version="3.0">
//	 package
//	 {
//	 import com.w3haus.scene.AbstractScreen;
//	 
//	 public class ScreenWithLoad extends AbstractScreen
//	 {
//	 public function ScreenWithLoad(name:String )
//	 {
//	 super(name, false, false, true);
//	 }
//	 
//	 override public function preloadAssets():void
//	 {
//	 MediaReader.application(onLoaderHandler);
//	 }
//	 
//	 override public function build():void
//	 {
//	 //build Something
//	 }
//	 
//	 override public function destroy():void
//	 {
//	 //destroy other things
//	 }
//	 
//	 private function onLoaderHandler (evt:) : void
//	 {
//	 switch (evt.command)
//	 {
//	 case MEDIA_COMPLETE :
//	 super.preloaderComplete(evt);
//	 break;
//	 }
//	 }
//	 }
//	 }
//	 * </listing>
//	 */
//	public function preloadAssets () : void{}
//	
//	// ___________________________________________________________________ PROTECTED METHODS
//	/**
//	 * Override this method
//	 * This method is called when the transition in and transition out END
//	 * Is resposable by unblock the screen
//	 */
//	protected function enable () : void { }
//	
//	/**
//	 * Override this method
//	 * This method is called when the transition in and transition out START
//	 * Is resposable by block the screen
//	 */
//	protected function disable () : void { }
//	
//	/**
//	 * Override this method
//	 * This method is called to activete the transition In
//	 */
//	protected function transitionIn():void
//	{
//		throw new Error ("HELLO!!! \n AbstractScreen.transitionIn\n Dont Forget In the end of Anim call super.endTransitionIn();");
//	}
//	
//	/**
//	 * Override this method
//	 * This method is called to activete the transition Out
//	 */
//	protected function transitionOut():void
//	{
//		throw new Error ("HELLO!!! \n AbstractScreen.transitionOut\n Dont Forget In the end of Anim call super.endTransitionOut();");
//	}
//	
//	/**
//	 * In the end of transition IN you MUST call this method
//	 */
//	protected function endTransitionIn ( ... args ) : void
//	{
//		enable(); 
//		dispatchEvent(_eOnShowFinish);
//	}
//	
//	/**
//	 * In the end of transition OUT you MUST call this method
//	 */
//	protected function endTransitionOut ( ... args ) : void
//	{
//		dispatchEvent(_eOnHideFinish);
//	}
//	
//	/**
//	 * In the end of the preloader complete you MUST call this method
//	 */
//	protected function preloaderComplete ( content : * = null , ... args ) : void
//	{
//		if (content != null)
//			_preloaderContent = content; _wasContentLoaded = true;
//			
//			dispatchEvent(_eOnPreload);
//			}
//	// ___________________________________________________________________ PRIVATE METHODS
//	
//	// ___________________________________________________________________ EVENTS
//	private function destroyHandler(e:Event = null):void 
//	{
//		_isVisible = false;
//		destroy();
//	}