I-Logix-RPY-Archive version 8.5.2 C 2030848
{ IProject 
	- _id = GUID c7c199ac-f92e-4612-85ad-a990fcde970b;
	- _myState = 8192;
	- _name = "StopwatchProject";
	- _lastID = 1;
	- _UserColors = { IRPYRawContainer 
		- size = 16;
		- value = 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 
	}
	- _defaultSubsystem = { ISubsystemHandle 
		- _m2Class = "ISubsystem";
		- _filename = "Default.sbs";
		- _subsystem = "";
		- _class = "";
		- _name = "Default";
		- _id = GUID ec94194f-97c4-48c4-bbc2-dd6abad1c592;
	}
	- _component = { IHandle 
		- _m2Class = "IComponent";
		- _filename = "StopwatchTest.cmp";
		- _subsystem = "";
		- _class = "";
		- _name = "StopwatchTest";
		- _id = GUID 1de1c920-9ecd-4f7c-bc64-6ead8cc0ec5d;
	}
	- Multiplicities = { IRPYRawContainer 
		- size = 4;
		- value = 
		{ IMultiplicityItem 
			- _name = "1";
			- _count = 6;
		}
		{ IMultiplicityItem 
			- _name = "*";
			- _count = -1;
		}
		{ IMultiplicityItem 
			- _name = "0,1";
			- _count = -1;
		}
		{ IMultiplicityItem 
			- _name = "1..*";
			- _count = -1;
		}
	}
	- Subsystems = { IRPYRawContainer 
		- size = 3;
		- value = 
		{ ISubsystem 
			- fileName = "Default";
			- _id = GUID ec94194f-97c4-48c4-bbc2-dd6abad1c592;
		}
		{ ISubsystem 
			- fileName = "StopwatchPkg";
			- _id = GUID 96ebdc78-b087-4f58-8e45-7e394313e113;
		}
		{ IProfile 
			- fileName = "IDFProfile";
			- _persistAs = "C:\\Rhapsody\\V60_RiC_InterruptDrivenFramework\\V60_RiC_InterruptDrivenFramework_rpy\\IDFProfile";
			- _id = GUID d5ee2130-51e1-4c6c-99cf-62836e1aaf1a;
			- _isReference = 1;
		}
	}
	- Diagrams = { IRPYRawContainer 
		- size = 1;
		- value = 
		{ IDiagram 
			- _id = GUID d275a1f7-225c-49dd-a684-2e7724e5cfe6;
			- _myState = 8192;
			- _name = "Model1";
			- _lastModifiedTime = "5.22.2022::5:13:46";
			- _graphicChart = { CGIClassChart 
				- _id = GUID 90b5e5d4-75af-44a9-b4e7-3d3c2adbe4a2;
				- m_type = 0;
				- m_pModelObject = { IHandle 
					- _m2Class = "IDiagram";
					- _id = GUID d275a1f7-225c-49dd-a684-2e7724e5cfe6;
				}
				- m_pParent = ;
				- m_name = { CGIText 
					- m_str = "";
					- m_style = "Arial" 10 0 0 0 1 ;
					- m_color = { IColor 
						- m_fgColor = 0;
						- m_bgColor = 0;
						- m_bgFlag = 0;
					}
					- m_position = 1 0 0  ;
					- m_nIdent = 0;
					- m_bImplicitSetRectPoints = 0;
					- m_nOrientationCtrlPt = 8;
				}
				- m_drawBehavior = 0;
				- m_bIsPreferencesInitialized = 0;
				- elementList = 1;
				{ CGIClass 
					- _id = GUID 5d81e85b-c2bc-48b1-b1e7-1c4110f6b198;
					- m_type = 78;
					- m_pModelObject = { IHandle 
						- _m2Class = "IClass";
						- _filename = "Default.sbs";
						- _subsystem = "Default";
						- _class = "";
						- _name = "TopLevel";
						- _id = GUID 164ccc74-a6f3-4fe7-b13c-91e7fff3e5a4;
					}
					- m_pParent = ;
					- m_name = { CGIText 
						- m_str = "TopLevel";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nOrientationCtrlPt = 5;
					}
					- m_drawBehavior = 0;
					- m_bIsPreferencesInitialized = 0;
					- m_AdditionalLabel = { CGIText 
						- m_str = "";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nOrientationCtrlPt = 1;
					}
					- m_polygon = 0 ;
					- m_nNameFormat = 0;
					- m_nIsNameFormat = 0;
					- Attrs = { IRPYRawContainer 
						- size = 0;
					}
					- Operations = { IRPYRawContainer 
						- size = 0;
					}
				}
				
				- m_access = 'Z';
				- m_modified = 'N';
				- m_fileVersion = "";
				- m_nModifyDate = 0;
				- m_nCreateDate = 0;
				- m_creator = "";
				- m_bScaleWithZoom = 1;
				- m_arrowStyle = 'S';
				- m_pRoot = GUID 5d81e85b-c2bc-48b1-b1e7-1c4110f6b198;
				- m_currentLeftTop = 0 0 ;
				- m_currentRightBottom = 0 0 ;
			}
			- _defaultSubsystem = { IHandle 
				- _m2Class = "ISubsystem";
				- _filename = "Default.sbs";
				- _subsystem = "";
				- _class = "";
				- _name = "Default";
				- _id = GUID ec94194f-97c4-48c4-bbc2-dd6abad1c592;
			}
		}
	}
	- Components = { IRPYRawContainer 
		- size = 1;
		- value = 
		{ IComponent 
			- fileName = "StopwatchTest";
			- _id = GUID 1de1c920-9ecd-4f7c-bc64-6ead8cc0ec5d;
		}
	}
}

