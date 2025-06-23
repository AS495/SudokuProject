import express from 'express';
import fetch from 'node-fetch';
import cors from 'cors';
import dotenv from 'dotenv';

dotenv.config();
const app = express();
const PORT = 3001;

app.use(cors());
app.get('/sudoku', async (req, res) => {
  try {
    const response = await fetch('https://api.api-ninjas.com/v1/sudokugenerate?difficulty=easy', {
        headers: { 'X-Api-Key': process.env.API_NINJAS_KEY }
    });
    if (!response.ok) {
      console.error('API error:', response.status, await response.text());
      return res.status(500).json({ error: 'API error', status: response.status });
    }
    const data = await response.json();
    const board = data.puzzle.map(row => row.map(cell => cell === null ? 0 : cell));
    res.json({ board });
  } catch (err) {
    console.error('Proxy error:', err);
    res.status(500).json({ error: 'Failed to fetch puzzle' });
  }
});

app.listen(PORT, () => console.log(`Proxy running on http://localhost:${PORT}`));