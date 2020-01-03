local class = require"middleclass"
local PanelBase = require "GUI.PanelBase"

local PanelTest = class("PanelTest", PanelBase)
local def = PanelTest
def.OnCreate = function(self)
    print(def, "OnCreate")
end

return PanelTest