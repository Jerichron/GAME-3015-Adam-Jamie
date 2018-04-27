using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;

[System.Serializable]
public class Item
{
    public string itemType;
    public float Posx;
    public float Posy;
    public float Posz;//location to place the prefab.
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
    public float Rotx;
    public float Roty;
    public float Rotz;
    public float Scalex;
    public float Scaley;
    public float Scalez;
}
