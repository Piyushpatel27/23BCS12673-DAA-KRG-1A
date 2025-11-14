const express = require("express");
const cors = require("cors");
const bodyParser = require("body-parser");
const axios = require("axios");
require('dotenv').config(); 

const app = express();
const PORT = process.env.PORT || 5000;
const GEMINI_API_KEY = process.env.GEMINI_API_KEY;

app.use(cors());
app.use(bodyParser.json());

// ✅ Chatbot Route
app.post("/chat", async (req, res) => {
    const userMessage = req.body.message;

    if (!userMessage) {
        return res.status(400).json({ error: "Message is required" });
    }

    try {
        const response = await axios.post(
            `https://generativelanguage.googleapis.com/v1/models/gemini-2.0-flash:generateContent?key=${GEMINI_API_KEY}`,
            {
                contents: [{ role: "user", parts: [{ text: userMessage }] }]
            },
            { headers: { "Content-Type": "application/json" } }
        );

        const botReply = response.data.candidates?.[0]?.content?.parts?.[0]?.text || "I couldn't process that.";
        res.json({ reply: botReply });
    } catch (error) {
        console.error("Error fetching response:", error?.response?.data || error.message);
        res.status(500).json({ error: "Failed to get a response from Gemini API" });
    }
});

app.listen(PORT, () => console.log(`✅ Server running on http://localhost:${PORT}`));
console.log("Current API key: ",GEMINI_API_KEY);