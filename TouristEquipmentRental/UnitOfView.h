#pragma once

#include "PrimaryView.h"
#include "SignInUpView.h"
#include "UserPanel.h"

class UnitOfView
{
private:
	PrimaryView _startView;
	SignInUpView _signInUpView;
	UserPanel _userPanel;
	
	void MainMenu(char choice);
	void UserMenu(char choice, User user, DatabaseOperator databaseOperator);
	void NavigationBar(char choice, User user, DatabaseOperator databaseOperator);

public:
	UnitOfView() {
		_startView = * new PrimaryView();
		_signInUpView = * new SignInUpView();
		_userPanel = * new UserPanel();
	}

	PrimaryView Start() {
		return _startView;
	}

	SignInUpView SigningOnIn() {
		return _signInUpView;
	}

	UserPanel Panel() {
		return _userPanel;
	}

	void LoadMenu() {
		char choice = _startView.RenderStartView();
		MainMenu(choice);
	}

	void LoadUserMenu(User user, DatabaseOperator databaseOperator) { 
		char choice = _userPanel.RenderUserMenu();
		UserMenu(choice, user, databaseOperator);
	}

	void LoadNavigation(User user, int widht, DatabaseOperator databaseOperator) {
		char choice = _userPanel.RenderNavigationBar(widht);
		NavigationBar(choice, user, databaseOperator);
	}

};

