#include "DNA_object_types.h"
#include "DNA_scene_types.h"

#include "BLI_alloca.h"
#include "BLI_math.h"
#include "BLI_math_geom.h"
#include "BLI_task.h"

#include "BKE_cdderivedmesh.h"
#include "BKE_editmesh.h"
#include "BKE_library_query.h"
#include "BKE_modifier.h"

#include "depsgraph_private.h"

#include "MEM_guardedalloc.h"

#include "MOD_util.h"

static DerivedMesh* applyModifier(ModifierData* md, Object* ob, DerivedMesh* dm, ModifierApplyFlag UNUSED(flag))
{
	return dm;
}

static void initData(ModifierData* md)
{
	MirrorModifierData* mmd = (MirrorModifierData*)md;
}

static void copyData(ModifierData* md, ModifierData* target)
{
#if 0
	MirrorModifierData* mmd = (MirrorModifierData*)md;
	MirrorModifierData* tmmd = (MirrorModifierData*)target;
#endif
	//modifier_copyData_generic(md, target);
}

static void updateDepgraph(ModifierData *md, DagForest *forest,
                           struct Main *UNUSED(bmain),
                           struct Scene *UNUSED(scene),
                           Object *UNUSED(ob),
                           DagNode *obNode)
{
	MirrorModifierData *mmd = (MirrorModifierData *) md;

	// if (mmd->mirror_ob) {
	// 	DagNode *latNode = dag_get_node(forest, mmd->mirror_ob);

	// 	dag_add_relation(forest, latNode, obNode, DAG_RL_OB_DATA, "Mirror Modifier");
	// }
}

ModifierTypeInfo modifierType_ZhangHang = {
	/* name */              "Zhang Hang",
	/* structName */        "ZhangHangModifierData",
	/* structSize */        sizeof(ZhangHangModifierData),
	/* type */              eModifierTypeType_Constructive,
	/* flags */             eModifierTypeFlag_AcceptsMesh,

	/* copyData */          NULL,

	/* deformVerts */       NULL,
	/* deformMatrices */    NULL,
	/* deformVertsEM */     NULL,
	/* deformMatricesEM */  NULL,
	/* applyModifier */     applyModifier,

	/* applyModifierEM */   NULL,
	/* initData */          initData,
	/* requiredDataMask */  NULL,
	/* freeData */          NULL,
	/* isDisabled */        NULL,
	/* updateDepgraph */    updateDepgraph,
	/* updateDepsgraph */   NULL,
	/* dependsOnTime */     NULL,
	/* dependsOnNormals */  NULL,
	/* foreachObjectLink */ NULL,
	/* foreachIDLink */     NULL,
	/* foreachTexLink */    NULL,
};