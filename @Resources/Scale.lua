--[[
Name=ScaleWindows
Author=Thankarezos
Information=Script to change the UI scale of other skins
Version=1.0
License=Creative Commons Attribution-Non-Commercial-Share Alike 3.0
]]

function Initialize()
	SourceSkin = SELF:GetOption('SkinToScale')
	Scale = SKIN:GetVariable(SourceSkin .. 'Scale', 'n/a')
	ScaleChange = SKIN:GetVariable('ScaleChange', 'n/a')
	Scroll = SKIN:GetVariable('Scroll', 'n/a')
	if Scroll == "true" then
		SKIN:Bang('!SetOption', 'Rainmeter', 'ContextTitle2', 'Disable Scroll')
	else
		SKIN:Bang('!SetOption', 'Rainmeter', 'ContextTitle2', 'Enable Scroll')
	end	
end
function Update()
	
	return tostring(Scale)
end
function Enlarge()
	if Scroll == "true" then
		if tonumber(Scale) < 4 then
			Scale = Scale + ScaleChange
			SKIN:Bang('!WriteKeyValue', 'Variables', SourceSkin .. 'Scale', Scale, '#@#Variables.inc')
		end
	end
end
function Smaller()
	if Scroll == "true" then
		if tonumber(Scale) > 0.2 then
			Scale = Scale - ScaleChange
			SKIN:Bang('!WriteKeyValue', 'Variables', SourceSkin .. 'Scale', Scale, '#@#Variables.inc')
		end
	end
end
function ONOFF()
	if Scroll == "true" then
		SKIN:Bang('!WriteKeyValue', 'Variables', 'Scroll', 'false', '#@#Variables.inc')
		SKIN:Bang('!SetOption', 'Rainmeter', 'ContextTitle2', 'Enable Scroll')
	else
		SKIN:Bang('!WriteKeyValue', 'Variables', 'Scroll', 'true', '#@#Variables.inc')
		SKIN:Bang('!SetOption', 'Rainmeter', 'ContextTitle2', 'Disable Scroll')
	end		
end