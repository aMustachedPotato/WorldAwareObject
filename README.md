# World Aware Object
**World Aware Object** is a UE plugin that adds a new UObject type that has world context. This means you can access SpawnActor, GetGameMode, and other BP nodes that were not previously available for regular Objects. Can be used in both blueprints and C++ to add gameplay code without making a whole actor, which I find very useful.

**Versions:** It should work on any version of UE, but I have only tested it on 4.27 and 5.4.

**Blueprint Usage:** Add a new blueprint class derived from "WAO". To create a World Aware object, call "Create World Aware Object"

**C++ Usage:** Add "WorldAwareObject" to your project build dependencies and create a class derived from "UWAO". To override OnCreate and OnDestroy events, override the _Implementation_ ( e.g. virtual void OnCreate_Implementation() override ). To create a World Aware Object, include "WAO.h" and call UWAO::CreateWorldAwareObject(...)

**Got more ideas for this plugin? Share them on the** [discord](https://discord.gg/bDfZd2Chg5)**!**
