#pragma once
#ifndef JT_VAODAT_H
#define JT_VAODAT_H

#include <vector>

#include <glad/glad.h>

struct VAODat { // vao data
	unsigned int VAO;
	unsigned int vertCount;
	inline VAODat(unsigned int vao, unsigned int vc) {
		VAO = vao;
		vertCount = vc;
	}
};

struct VertAttrPtr {
	int siz;
	int stride;
	int offset;
	VertAttrPtr(int s, int str, int off) {
		siz = s;
		stride = str;
		offset = off;
	}
};

struct SmartVAO {
	unsigned int VAO, VBO, EBO;
	unsigned int vertc;
	inline SmartVAO(float verts[], unsigned int indexes[], unsigned int ic, 
		std::vector<VertAttrPtr> vap) {
		vertc = ic;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexes), indexes, GL_STATIC_DRAW);
		unsigned int i = 0;
		for (auto &vp : vap) {
			glVertexAttribPointer(i, vp.siz, GL_FLOAT, GL_FALSE, 
				vp.stride * sizeof(float), (void*)(vp.offset * sizeof(float)));
			glEnableVertexAttribArray(i);
			i++;
		}
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		std::cout << "geterated vao into " << VAO << std::endl;
	}
	inline ~SmartVAO() {
		std::cout << "deleting vao " << VAO << std::endl;
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
	}
	inline void bind() {
		glBindVertexArray(VAO);
		std::cout << "VAO " << VAO << " binded" << std::endl;
	}
};

#endif
