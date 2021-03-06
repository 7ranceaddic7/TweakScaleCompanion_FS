source ../CONFIG.inc

PACKAGE=TweakScaleCompanion.FS
TARGETDIR="TweakScaleCompanion/FS"
TARGETBINDIR="$TARGETDIR/Plugins"
PROJECTSDIR="$PACKAGE/"
DLLS="TweakScaleCompanion_FS TweakScalerFSBuoyancy"

PROJECT_BRANCH=`git branch | grep \* | cut -d ' ' -f2`
if [ "$PROJECT_BRANCH" == "master" ] ; then
    # Release mode
    PROJECT_STATE="-BETA"
else
    # Note: Add a leading dash when this value is present!
    PROJECT_STATE="-BETA"
fi

VERSION=$( cat $PACKAGE.version | tr '\n' ' ' | sed -n -E 's/^.*?"VERSION\":\{.*"MAJOR":([0-9]+?),.*?"MINOR":([0-9]+?),.*?"PATCH":([0-9]+?),.*?"BUILD":([0-9]+?).*?\}.*$/\1.\2.\3.\4/p' )
