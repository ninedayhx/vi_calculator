<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="18008000">
	<Item Name="我的电脑" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">我的电脑/VI服务器</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">我的电脑/VI服务器</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="calc.vi" Type="VI" URL="../calc.vi"/>
		<Item Name="Calculator.ico" Type="Document" URL="../Calculator.ico"/>
		<Item Name="菜单.rtm" Type="Document" URL="../菜单.rtm"/>
		<Item Name="显示.ctl" Type="VI" URL="../显示.ctl"/>
		<Item Name="依赖关系" Type="Dependencies">
			<Item Name="test_Dll.dll" Type="Document" URL="../test_Dll.dll"/>
		</Item>
		<Item Name="程序生成规范" Type="Build">
			<Item Name="calc" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{B7707D3C-A6C3-4B8E-8A57-5A714FE2E6D6}</Property>
				<Property Name="App_INI_GUID" Type="Str">{FE45E8ED-DF26-4A8D-97F1-0BD367797F9D}</Property>
				<Property Name="App_serverConfig.httpPort" Type="Int">8002</Property>
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{82E82C11-0899-486F-8529-9DC25AB6C1D1}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">calc</Property>
				<Property Name="Bld_defaultLanguage" Type="Str">ChineseS</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../builds/NI_AB_PROJECTNAME/bin</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{9A63AFAD-2501-4243-A73E-6006BDF814D5}</Property>
				<Property Name="Bld_version.build" Type="Int">1</Property>
				<Property Name="Bld_version.major" Type="Int">1</Property>
				<Property Name="Destination[0].destName" Type="Str">calc.exe</Property>
				<Property Name="Destination[0].path" Type="Path">../builds/NI_AB_PROJECTNAME/bin/calc.exe</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">支持目录</Property>
				<Property Name="Destination[1].path" Type="Path">../builds/NI_AB_PROJECTNAME/bin/data</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Exe_actXServerName" Type="Str">Calc</Property>
				<Property Name="Exe_actXServerNameGUID" Type="Str"></Property>
				<Property Name="Source[0].itemID" Type="Str">{4EE9F262-F56A-4A16-B218-A2C9148BEC4B}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/我的电脑/calc.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_fileDescription" Type="Str">calc</Property>
				<Property Name="TgtF_internalName" Type="Str">calc</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">版权 2021 </Property>
				<Property Name="TgtF_productName" Type="Str">calc</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{ECB75BBC-4FA0-45CE-A91A-5442BF4F0E20}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">calc.exe</Property>
				<Property Name="TgtF_versionIndependent" Type="Bool">true</Property>
			</Item>
		</Item>
	</Item>
</Project>
