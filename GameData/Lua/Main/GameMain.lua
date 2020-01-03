local class = require "middleclass"

local l_instance = nil

local GameMain = class("GameMain")
GameMain.static.Instance = function()
    if not l_instance then
        l_instance = GameMain()
    end

    return l_instance
end

function GameMain:GameInit()
    print("GameMain", "GameInit", self)

    local PanelTest = require "GUI.PanelTest"
    PanelTest:CreatePanel("a")
end

return GameMain