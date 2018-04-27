using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;

[System.Serializable]
public class Item
{
    public string itemType;
    public float VecLocx;
    public float VecLocy;
    public float VecLocz;//location to place the prefab.
    public Vector3 Location;
    public Vector3 Rotation; //the rotation in worldspace.
    public Vector3 Scale; //scale of the item. 
    public bool Rigidbody;
    public bool MeshFilter;
    public int[] triangles;
    public int numVerts;
    public int[] Verts;
    public bool BoxCollider;
    public bool MeshRenderer;
    public float VecRotX;
    public float VecRotY;
    public float VecRotZ;
    public float VecSclX;
    public float VecSclY;
    public float VecSclZ;
}
